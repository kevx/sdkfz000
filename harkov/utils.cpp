
#include "file_walker.h"
#include <string>
#include <stdarg.h>
#include <wchar.h>
#include <windows.h>
#include <memory.h>
#include <Iphlpapi.h>
#include <stdio.h>
#include <sys/stat.h>


bool str_endswith(const wstring &s, const wstring &sfx) {
	size_t p = s.rfind(sfx);
	if (p != string::npos) {
		if (p == (s.length() - sfx.length())) return true;
	}
	return false;
}

wstring substr_after(const wstring& s, const wstring& skip) {
	size_t p = s.find(skip);
	if (p == wstring::npos) {
		return NULL;
	}
	
	return s.substr(skip.length() + p);
}

wstring str_format(const wchar_t* fmt, ...) {
    int size = 100;
    wstring str;
    va_list ap;
    while (1) {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnwprintf((wchar_t *)str.c_str(), size, fmt, ap);
        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            return str;
        }
        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }
    return str;
}

FILE* wfopen(const wchar_t* filename, const wchar_t* mode) {  
    char fn[MAX_PATH];  
    char m[MAX_PATH];  
    wcstombs(fn, filename, MAX_PATH);  
    wcstombs(m, mode, MAX_PATH);  
    return fopen(fn, m);  
}  

long wfsize(const wchar_t *filename) {
	struct stat st; 
    if (wstat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

long fsize(const char *filename) {
    struct stat st; 
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1; 
}

wstring query_hostname() 
{
	unsigned long bufLen = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t buf[bufLen];
	memset(buf, 0, sizeof(wchar_t) * bufLen);
	GetComputerNameW(buf, &bufLen);
	return wstring(buf);
}

string query_mac_addr() {
	IP_ADAPTER_INFO adapterInfo[16];
	DWORD dwBufLen = sizeof(adapterInfo);
	DWORD dwStatus = GetAdaptersInfo(adapterInfo, &dwBufLen);
	PIP_ADAPTER_INFO pAdapterInfo = adapterInfo;
	const char* defaultMac = "00-00-00-00-00-00";
	string s(defaultMac);
	char buf[5];
	do {
		if (pAdapterInfo->Type == MIB_IF_TYPE_ETHERNET || 
			pAdapterInfo->Type == IF_TYPE_IEEE80211) 
		{
			IP_ADDR_STRING gw = pAdapterInfo->GatewayList;
			if (strncmp("0.0.0.0", gw.IpAddress.String, 20)) {
				s.clear();
				for (unsigned int i = 0; i < pAdapterInfo->AddressLength; i++) {
					memset(buf, 0, 5);
					if (i == (pAdapterInfo->AddressLength - 1)) 
						sprintf(buf, "%.2X", (int) pAdapterInfo->Address[i]);
					else
						sprintf(buf, "%.2X-", (int) pAdapterInfo->Address[i]);
					s.append(buf);
				}
				break;
			}
		}
		pAdapterInfo = pAdapterInfo->Next;
	} while (pAdapterInfo);
	return s;
}

wstring query_mac_addrw()
{
	string s = query_mac_addr();
	return std::wstring(s.begin(), s.end());
}
