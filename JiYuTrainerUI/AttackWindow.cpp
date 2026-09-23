#include "stdafx.h"
#include "AttackWindow.h"
#include "ScanIPWindow.h"
#include "resource.h"
#include "../JiYuTrainer/SysHlp.h"
#include "../JiYuTrainer/NetUtils.h"
#include "../JiYuTrainer/StringSplit.h"
#include "../JiYuTrainer/StringHlp.h"
#include <regex>

extern int screenWidth, screenHeight;

AttackWindow::AttackWindow(HWND parentHWnd) : 
	CommonWindow(parentHWnd, 570, 520, 
		L"JiYuTrainerAttackWindow", L"極域電子教室封包 (UDP) 重送攻擊 - by ht0Ruial",
		IDR_HTML_ATTACK)
{
	init();
	Show();
	JyUdpAttack::currentJyUdpAttack->sendResultReceivehWnd = _hWnd;
}
AttackWindow::~AttackWindow()
{
}

bool AttackWindow::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
	sciter::dom::element ele(he);
	if (type == HYPERLINK_CLICK)
	{
		if (ele.get_attribute("data-type") == L"ip_link") {
			input_target_ip.set_value(sciter::value(ele.get_attribute("data-ip")));
		} else if (ele.get_attribute("href").find_first_of(L"http") == 0) {
			SysHlp::OpenUrl(ele.get_attribute("href").c_str());
		}
	}
	else if (type == BUTTON_CLICK)
	{
		sciter::string id = ele.get_attribute("id");
		if (id == L"btn_scan_ip") {
			if (currentScanIPWnd)
				currentScanIPWnd->Show();
			else
				currentScanIPWnd = new ScanIPWindow(_hWnd);
		}
		else if (id == L"btn_scan_port")
			JyUdpAttack::currentJyUdpAttack->CheckStudentMainTCPPort(_hWnd);
		else if (id == L"btn_send_msg")
			SendText();
		else if (id == L"btn_send_cmd")
			SendCmd();
		else if (id == L"btn_send_shutdown")
			SendShutdown();
		else if (id == L"btn_send_reboot")
			SendReboott();
	}
	return false;
}
LRESULT AttackWindow::onWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, BOOL* handled)
{
	switch (message)
	{
	case WM_MY_WND_CLOSE: {
		void* wnd = (void*)wParam;
		if (wnd == static_cast<CommonWindow*>(currentScanIPWnd)) {
			currentScanIPWnd->Release();
			currentScanIPWnd = nullptr;
		}
		*handled = TRUE;
		return 0;
	}
	case WM_MY_FORCE_HIDE: {
		Hide();
		if(currentScanIPWnd) SendMessage(currentScanIPWnd->get_hwnd(), WM_MY_FORCE_HIDE, 0, 0);
		*handled = TRUE;
		return 0;
	}
	case WM_MY_GET_SM_TICP_PORT_FINISH: {
		if (wParam == NOT_FOUND_JY_PORT) MessageBox(hWnd, L"未找到極域 PID，請確認極域正在執行中。", L"提示", MB_OK);
		else if(wParam == FAILED_FOUND_JY_PORT) MessageBox(hWnd, L"取得 TCP 表失敗", L"提示", MB_OK);
		else input_target_port.set_value(sciter::value((int)wParam));
		*handled = TRUE;
		return 0;
	}
	case WM_MY_SEND_ADD_RESULT: {
		auto* str = (std::wstring*)wParam;
		AddStringToReult(str->c_str());
		delete str;
		*handled = TRUE;
		return 0;
	}
	default:
		return 0;
	}
}

bool AttackWindow::SendCommonCheck(std::vector<std::wstring> *ips, DWORD *port)
{
	std::wstring str = input_target_ip.get_value().get(L"");
	if (str.empty()) {
		AddStringToReult(L"請輸入目標 IP 位址！");
		return false;
	}

	*port = input_target_port.get_value().get(-1);
	if (*port < 0 || *port > 65535) {
		AddStringToReult(L"連接埠錯誤，連接埠必須為 0-65535 的數字");
		return false;
	}

	SplitString(str, *ips, L",");
	int i = 0;
	for (std::wstring ip : *ips) {
		i++;
		std::wregex express(L"^(25[0-5]|2[0-4]\\d|[0-1]?\\d?\\d)(\\.(25[0-5]|2[0-4]\\d|[0-1]?\\d?\\d)){3}$");
		if (!std::regex_match(ip.begin(), ip.end(), express)) {
			AddStringToReult(FormatString(L"第 %d 個 IP 位址（%s）格式不正確，必須是合法的 IPv4 位址", i, ip.c_str()).c_str());
			return false;
		}
	}

	return true;
}

void AttackWindow::SendCmd() {
	auto cmd = input_send_cmd.get_value().to_string();
	if (cmd.empty()) {
		AddStringToReult(L"請輸入要發送的指令！");
		return;
	}
	if (cmd.length() > 512) {
		AddStringToReult(L"指令過長，請刪減部分內容");
		return;
	}
	std::vector<std::wstring> ips;
	DWORD port;
	if (!SendCommonCheck(&ips, &port))
		return;
	for (std::wstring ip : ips)
		JyUdpAttack::currentJyUdpAttack->SendCommand(ip, port, cmd);
}
void AttackWindow::SendText() {
	auto cmd = input_send_message.get_value().to_string();
	if (cmd.empty()) {
		AddStringToReult(L"請輸入要發送的文字！");
		return;
	}
	if (cmd.length() > 100) {
		AddStringToReult(L"文字過長，請刪減部分內容");
		return;
	}
	std::vector<std::wstring> ips;
	DWORD port;
	if (!SendCommonCheck(&ips, &port))
		return;
	for (std::wstring ip : ips)
		JyUdpAttack::currentJyUdpAttack->SendText(ip, port, cmd);
}
void AttackWindow::SendShutdown() {
	if (MessageBox(_hWnd, L"確認發送該指令？", L"提示", MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {

		std::vector<std::wstring> ips;
		DWORD port;
		if (!SendCommonCheck(&ips, &port))
			return;
		for(std::wstring ip : ips)
			JyUdpAttack::currentJyUdpAttack->SendShutdown(ip, port);
	}
}
void AttackWindow::SendReboott() {
	if (MessageBox(_hWnd, L"確認發送該指令？", L"提示", MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {

		std::vector<std::wstring> ips;
		DWORD port;
		if (!SendCommonCheck(&ips, &port))
			return;
		for (std::wstring ip : ips)
			JyUdpAttack::currentJyUdpAttack->SendReboot(ip, port);
	}
}
void AttackWindow::AddStringToReult(LPCWSTR str)
{
	auto ele = result_list.create("div", str);
	result_list.append(ele);
	result_list.scroll_to_view();
}

sciter::value AttackWindow::docunmentComplete()
{
	CommonWindow::docunmentComplete();

	sciter::dom::element root = get_root();
	result_list = root.get_element_by_id(L"result_list");
	input_target_ip = root.get_element_by_id(L"input_target_ip");
	input_target_port = root.get_element_by_id(L"input_target_port");
	input_send_message = root.get_element_by_id(L"input_send_message");
	input_send_cmd = root.get_element_by_id(L"input_send_cmd");

	return sciter::value(true);
}


