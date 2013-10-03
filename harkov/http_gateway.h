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
	
private:
	HINTERNET _inetSession;
	
	const static wstring _UA;
	
	void writeToLocal(HINTERNET req, string& localfile);
};

#endif // HTTPGATEWAY_H
