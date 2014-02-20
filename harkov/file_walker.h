#ifndef FILEWALKER_H
#define FILEWALKER_H

#include "global.h"
#include <vector>
#include <string>

class FileWalker
{
public:
	FileWalker(long delay);
	~FileWalker();

	void find(const wchar_t* root, int depth);
	void find(const wchar_t* root);
	void clear();
	
	vector<wstring> getResults();
	
private:
	int _maxDepth;
	long _delay;
	const static int DEFAULT_DEPTH;
	
	vector<wstring> _files;
	vector<wstring> _exts;
};
#endif // FILEWALKER_H
