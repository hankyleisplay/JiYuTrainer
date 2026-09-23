#pragma once
#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <string>  
#include <vector>

//字串協助類別
class StringHlp
{
public:
	StringHlp();
	~StringHlp();

	static std::string & FormatString(std::string & _str, const char * _Format, ...);
	static std::wstring & FormatString(std::wstring & _str, const wchar_t * _Format, ...);
	static std::wstring FormatString(const wchar_t * format, ...);
	static std::wstring FormatString(const wchar_t *_Format, va_list marker);
	static std::string FormatString(const char *_Format, va_list marker);
	static std::string FormatString(const char * format, ...);

	static wchar_t* Utf8ToUnicode(const char* szU8);
	static char* UnicodeToAnsi(const wchar_t* szStr);
	static char* UnicodeToUtf8(const wchar_t* unicode);
	static wchar_t* AnsiToUnicode(const char* szStr);
	static void FreeStringPtr(void * ptr);

	static std::string* FormatStringPtr2A(std::string *_str, const char * _Format, ...);
	static std::wstring * FormatStringPtr2W(std::wstring *_str, const wchar_t * _Format, ...);
	static std::wstring * FormatStringPtrW(const wchar_t *format, ...);
	static std::string *FormatStringPtrA(const char *format, ...);

	//檢查字串是否為空
	static BOOLEAN StrEmeptyW(LPCWSTR str);
	//檢查字串是否為空
	static BOOLEAN StrEmeptyA(LPCSTR str);

	static LPCWSTR StrUpW(LPCWSTR str);
	static LPCSTR StrUpA(LPCSTR str);
	static LPCWSTR StrLoW(LPCWSTR str);
	static LPCSTR StrLoA(LPCSTR str);
	static LPCWSTR StrAddW(LPCWSTR str1, LPCWSTR str2);
	static LPCSTR StrAddA(LPCSTR str1, const LPCSTR str2);
	//檢查字串是否相等
	static BOOL StrEqualA(LPCSTR str1, LPCSTR str2);
	//檢查字串是否相等
	static BOOL StrEqualW(const wchar_t* str1, const wchar_t* str2);
	static LPCSTR IntToStrA(int i);
	static LPCWSTR IntToStrW(int i);
	static LPCWSTR MIntToStrW(int i);
	static LPCSTR LongToStrA(long i);
	static LPCWSTR LongToStrW(long i);
	static int StrToIntA(char * str);
	static int StrToIntW(LPCWSTR str);
	static DWORD StrSplitA(char * str, LPCSTR splitStr, LPCSTR * result, char ** lead);
	static DWORD StrSplitW(wchar_t * str, const LPCWSTR splitStr, LPCWSTR * result, wchar_t ** lead);
	static BOOL StrContainsA(LPCSTR str, LPCSTR testStr, LPCSTR * resultStr);
	static BOOL StrContainsW(LPCWSTR str, LPCWSTR testStr, LPCWSTR * resultStr);
	static BOOL StrContainsCharA(LPCSTR str, CHAR testStr);
	static BOOL StrContainsCharW(LPCWSTR str, WCHAR testStr);
	static int HexStrToIntW(wchar_t *s);
	static long long HexStrToLongW(wchar_t *s);
private:

};

//格式化字串（僅於目前模組或 /MD 執行階段程式庫編譯時使用），其他模組請使用 FormatStringPtr
#define FormatString StringHlp::FormatString
//檢查字串是否包含特定字元
#define StrContainsChar StringHlp::StrContainsCharW
//檢查字串是否為空
#define StrEmepty StringHlp::StrEmeptyW
//檢查字串是否為空
#define StrEmeptyAnsi StringHlp::StrEmeptyA
//檢查字串是否相等
#define StrEqual StringHlp::StrEqualW
//檢查字串是否相等A
#define StrEqualAnsi StringHlp::StrEqualA
//窄字元轉寬字元 (ANSI to Unicode)
#define A2W StringHlp::AnsiToUnicode
//寬字元轉窄字元 (Unicode to ANSI)
#define W2A StringHlp::UnicodeToAnsi
//格式化字串，回傳之指標請使用 FreeStringPtr 釋放
#define FormatStringPtr StringHlp::FormatStringPtrW
//釋放由 StringHlp 類別回傳之字串指標
#define FreeStringPtr(szPtr) StringHlp::FreeStringPtr((void*)szPtr)






