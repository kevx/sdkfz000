#include <stdio.h>
#include <windows.h>
#include "file_walker.h"
#include "http_gateway.h"
#include "crypto.h"
#include "log4c.h"

void test_http_gw() {
	HttpGateway hg;
	wstring s(L"http://myvcr.googlecode.com/files/myvcr_v1005.zip");
	string f("Q:\\hg.html");
	hg.fetch(s, f);
}

void test_file_walker() {
	FileWalker fw;
	Crypto c;
	fw.find(L"F:\\test", 0);
	
	vector<wstring> ret = fw.getResults();
	for (size_t i = 0; i < ret.size(); i++) {
		string md5 = c.md5File(ret[i]);
		wprintf(L"%s...", ret[i].c_str());
		printf("md5=%s\n", md5.c_str());
	}
}

void test_crypto() {
	Crypto c;
	wstring s(L"C:\\windows\\win.ini");
	string md5 = c.md5File(s);
	printf("md5=%s\n", md5.c_str());
}


void init_as_test()
{
	//test_http_gw();
	//test_file_walker();
	wstring s = query_mac_addr();
	Log4c::Instance()->log(str_format(L"%d_%s\n", ::GetTickCount(), s.c_str()));
}
