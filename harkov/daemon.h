/**
daemon base interface
*/
#ifndef DAEMON_H
#define DAEMON_H

#include <windows.h>

class AbstractDaemon {

	
	public:virtual void run() = 0;
	
	private:HANDLE handle;
	private:DWORD dwTid;
	protected:bool end;
	
	public:bool isEnd() {
		return end;
	}
	
	~AbstractDaemon() {
		::CloseHandle(handle);
	}
	
	public:void start() {
		handle = ::CreateThread(NULL, 0, AbstractDaemon::beginThread, this, 0, &dwTid);
		end = false;
	}
	
	public:static DWORD WINAPI beginThread(LPVOID param) {
		AbstractDaemon *ad = (AbstractDaemon*)param;
		ad->run();
	}
};

class DaemonWalker : public AbstractDaemon {
	
	public: void run();
	public: DaemonWalker();
	private: void upload(wstring& file);
	private: long lastRunning;
};

#endif
