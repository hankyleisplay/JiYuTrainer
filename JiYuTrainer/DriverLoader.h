#pragma once
#include "stdafx.h"

//載入驅動程式
//    lpszDriverName：驅動程式服務名稱
//    driverPath：驅動程式完整路徑
//    lpszDisplayName：nullptr
BOOL MLoadKernelDriver(const wchar_t* lpszDriverName, const wchar_t* driverPath, const wchar_t* lpszDisplayName);
//卸載驅動程式
//    szSvrName：服務名稱
BOOL MUnLoadKernelDriver(const wchar_t* szSvrName);
BOOL MUnLoadDriverServiceWithMessage(const wchar_t * szSvrName);
//開啟驅動程式
BOOL XOpenDriver();
//回傳驅動程式是否已載入
BOOL XDriverLoaded();

BOOL XTestDriverCanUse();

BOOL XInitSelfProtect();

BOOL XLoadDriver();

BOOL XCloseDriverHandle();

BOOL XUnLoadDriver();
