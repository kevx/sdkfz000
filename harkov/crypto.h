#ifndef CRYPTO_H
#define CRYPTO_H

#include "global.h"
#include <windows.h>
#include <wincrypt.h>

class Crypto
{
public:
	Crypto();
	~Crypto();

	string md5Str(string &in);
	string md5File(wstring &file);
	string md5(const char* buff, unsigned long size);
private:
	HCRYPTPROV _ctx;
};

#endif // CRYPTO_H
