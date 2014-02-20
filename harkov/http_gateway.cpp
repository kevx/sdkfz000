#include "http_gateway.h"
#include <iostream>
#include <fstream>

const wstring HttpGateway::_UA = L"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36";

HttpGateway::HttpGateway()
{
	inetCore = ::InternetOpenW(_UA.c_str(), INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
}

HttpGateway::~HttpGateway()
{
	if (inetCore != NULL)
		::InternetCloseHandle(inetCore);
}

bool HttpGateway::fetch(wstring& url, string& localfile) 
{
	DWORD reqFlags = INTERNET_FLAG_NO_UI|
		INTERNET_FLAG_NO_AUTH|
		INTERNET_FLAG_PRAGMA_NOCACHE|
		INTERNET_FLAG_NO_CACHE_WRITE|
		INTERNET_FLAG_RELOAD;
			
	HINTERNET req = ::InternetOpenUrlW(inetCore, url.c_str(), 0, 0, reqFlags, 0);
	writeToLocal(req, localfile);
	::InternetCloseHandle(req);
	return true;
}

bool HttpGateway::upload(wstring& server, wstring& uri, wstring& local) {
	HINTERNET conn = ::InternetConnectW(
		inetCore, 
		server.c_str(), 
		INTERNET_DEFAULT_HTTP_PORT, 
		NULL, 
		NULL, 
		INTERNET_SERVICE_HTTP, 
		0, 
		0
	);
	
	LPCWSTR acc[] = {
		L"*/*", NULL
	};
	
	HINTERNET req = ::HttpOpenRequestW(
		conn, 
		L"POST", 
		uri.c_str(), 
		NULL, 
		NULL, 
		acc, 
		0, 
		INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_NO_AUTO_REDIRECT | INTERNET_FLAG_HYPERLINK
	);
	
	wstring mac = query_mac_addrw();
	wstring headers;
	headers.append(L"X-mac-addr: ");
	headers.append(mac);
	
	HttpAddRequestHeadersW(req, mac.c_str(), 0, HTTP_ADDREQ_FLAG_ADD_IF_NEW);
	
	FILE* f = wfopen(local.c_str(), L"rb");
	DWORD bufsize = 1024*100;
	DWORD totalsize = wfsize(local.c_str());

	INTERNET_BUFFERS ib;
	memset(&ib, 0, sizeof(INTERNET_BUFFERS));
	ib.dwStructSize = sizeof(INTERNET_BUFFERS);
	ib.dwBufferTotal = totalsize;
	ib.dwBufferLength = bufsize;

	::HttpSendRequestEx(req, &ib, NULL, 0, 0);
	
    char *buffer = new char[bufsize];
    DWORD dwWritten = 0;
    size_t readBytes = 0;
    while (!feof(f)) {
    	memset(buffer, 0, bufsize * sizeof(char));
    	readBytes = fread(buffer, sizeof(char), bufsize, f);
    	::InternetWriteFile(req, buffer, readBytes, &dwWritten);
    }

    fclose(f);
	::HttpEndRequest(req, NULL, 0, 0);
	::InternetCloseHandle(conn);
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

