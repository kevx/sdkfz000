#ifndef HTTPGATEWAY_H
#define HTTPGATEWAY_H

#include "global.h"
#include <string>
#include <windows.h>
#include <wininet.h>

class HttpGateway
{
public:
	HttpGateway();
	~HttpGateway();

	bool fetch(wstring& url, string& localfile);
	bool upload(wstring& server, wstring& uri, wstring& local);
private:
	HINTERNET inetCore;
	
	const static wstring _UA;
	
	void writeToLocal(HINTERNET req, string& localfile);
	void writeToRemote(HINTERNET req, wstring& localfile);
};

#endif // HTTPGATEWAY_H
