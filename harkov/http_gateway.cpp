#include "http_gateway.h"
#include <iostream>
#include <fstream>

const wstring HttpGateway::_UA = L"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36";

HttpGateway::HttpGateway()
{
	_inetSession = ::InternetOpenW(_UA.c_str(), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
}

HttpGateway::~HttpGateway()
{
	if (_inetSession != NULL)
		::InternetCloseHandle(_inetSession);
}

bool HttpGateway::fetch(wstring& url, string& localfile) 
{
	DWORD reqFlags = INTERNET_FLAG_NO_UI|
		INTERNET_FLAG_NO_AUTH|
		INTERNET_FLAG_PRAGMA_NOCACHE|
		INTERNET_FLAG_NO_CACHE_WRITE|
		INTERNET_FLAG_RELOAD;
			
	HINTERNET req = ::InternetOpenUrlW(_inetSession, url.c_str(), 0, 0, reqFlags, 0);
	writeToLocal(req, localfile);
	::InternetCloseHandle(req);
	return true;
}

void HttpGateway::writeToLocal(HINTERNET req, string & localfile) {
	char contentBuf[1024];
	DWORD byteRead = 0;
	ofstream out(localfile.c_str(), ios::binary | ios::out);
	while (::InternetReadFile(req, contentBuf, sizeof(contentBuf), &byteRead) && byteRead > 0) {
		out.write(contentBuf, byteRead);
		memset(contentBuf, 0, sizeof(contentBuf));
	}
	out.close();
}

