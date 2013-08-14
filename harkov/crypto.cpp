#include "crypto.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>

Crypto::Crypto()
{
	::CryptAcquireContext(&_ctx, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_MACHINE_KEYSET);
}

Crypto::~Crypto()
{
	::CryptReleaseContext(_ctx, 0);
}

string Crypto::md5(const char* buff, unsigned long size)
{
	string str;
	HCRYPTHASH hash;
	unsigned char outBuff[0x7F];
	char tmp[3];
	DWORD hashLen = 16;
	if(::CryptCreateHash(_ctx, CALG_MD5, 0, 0, &hash)) {
		if(::CryptHashData(hash, (unsigned char*)buff, size, 0)) {
			if(::CryptGetHashParam(hash, HP_HASHVAL, outBuff, &hashLen, 0)) {
				for (size_t i = 0; i < 16; i++) {
					sprintf(tmp, "%02x", outBuff[i]);
					str.append(tmp);
					memset(tmp, 0, sizeof(tmp));
				}
			}
		}
	}
	
	::CryptDestroyHash(hash);
	return str;
}

string Crypto::md5Str(string &in)
{
	const char* input = in.c_str();
	DWORD inputLen = in.length();
	return md5(input, inputLen);
}

string Crypto::md5File(wstring &wfile)
{
	struct _stat attr;
	_wstat(wfile.c_str(), &attr);
	size_t fileLen = attr.st_size;
	char* buff = new char[fileLen];
	memset(buff, 0, fileLen * sizeof(char));
	
	FILE* file = _wfopen(wfile.c_str(), L"rb");
	fread(buff, 1, fileLen, file);
	fclose(file);
	string result = md5(buff, fileLen);
	delete[] buff;
	return result;
}