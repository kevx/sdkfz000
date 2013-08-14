#ifndef LOG4C_H
#define LOG4C_H

#include "global.h"

#include <vector>

#define MAX_BUFF_SIZE 10

class Log4c
{
	static Log4c* ms_instance;

public:
	static Log4c* Instance();
	static void setLogFile(wstring& filePath);
	static void Release();

	void log(wstring s);
	
	void flush();
private:
	Log4c();
	~Log4c();

	vector<wstring> _internalBuff; 
	wstring _logFile;
};

#endif // LOG4C_H
