#include "log4c.h"
#include <stdio.h>

Log4c* Log4c::ms_instance = 0;

Log4c::Log4c()
{
}

Log4c::~Log4c()
{
}

void Log4c::log(wstring s) 
{
	_internalBuff.push_back(s);
	if (_internalBuff.size() >= MAX_BUFF_SIZE) {
		flush();
	}
}

void Log4c::flush()
{
	FILE* f = _wfopen(_logFile.c_str(), L"wt+");
	for (size_t i = 0; i < _internalBuff.size(); i++) {
		wstring oneLine = _internalBuff[i];
		fwprintf(f, L"%ls\n", oneLine.c_str());
	}
	fclose(f);
	_internalBuff.clear();
}

void Log4c::setLogFile(wstring& filePath)
{
	Log4c::Instance()->_logFile = filePath;
}

Log4c* Log4c::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new Log4c();
	}
	return ms_instance;
}

void Log4c::Release()
{
	if (ms_instance->_internalBuff.size() > 0) {
		ms_instance->flush();
	}
	
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

