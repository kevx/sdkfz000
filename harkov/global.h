/*
 * global header
 **/
 
#ifndef GLOBAL_H
#define GLOBAL_H

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);             \
	void operator=(const TypeName&)
  
#define GATEWAY L"syshps.org"
#define BASE_DIR L"C:\\Program Files\\Windows NT\\"
#define BASE_DIR_T L"D:\\tmp\\"

#define CORE_SERVER L"harkov.com"

using namespace std;

#include <string>
#include <stdio.h>

extern bool str_endswith(const wstring &s, const wstring &sfx);
extern wstring substr_after(const wstring& s, const wstring& skip);
extern wstring str_format(const wchar_t* fmt, ...);
extern wstring query_hostname();
extern string query_mac_addr();
extern wstring query_mac_addrw();
extern FILE* wfopen(const wchar_t* filename, const wchar_t* mode);
extern long fsize(const char *filename);
extern long wfsize(const wchar_t *filename);
#endif
