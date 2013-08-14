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

using namespace std;

#include <string>

extern bool str_endswith(const wstring &s, const wstring &sfx);
extern wstring substr_after(const wstring& s, const wstring& skip);
extern wstring str_format(const wchar_t* fmt, ...);
extern wstring query_hostname();
extern wstring query_mac_addr();

#endif