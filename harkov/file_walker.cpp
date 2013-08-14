#include "file_walker.h"
#include <windows.h>
#include <stdio.h>

/**
 * File Walker
 * 06/15/2013
 */
const int FileWalker::DEFAULT_DEPTH = 10;

FileWalker::FileWalker()
{
	_maxDepth = (DEFAULT_DEPTH);
	wstring doc(L".doc");
	wstring xls(L".xls");
	wstring docx(L".docx");
	wstring xlsx(L".xlsx");
	
	_exts.push_back(doc);
	_exts.push_back(xls);
	_exts.push_back(docx);
	_exts.push_back(xlsx);
}

FileWalker::~FileWalker()
{
}

void FileWalker::find(const wchar_t* root)
{
	this->find(root, 0);
}

void FileWalker::find(const wchar_t* root, int depth) 
{
	if (depth > _maxDepth) return;
	WIN32_FIND_DATAW findData;
	
	wstring path(root);
	wstring sFile;
	path.append(L"\\*.*");
	
	HANDLE hFind = ::FindFirstFileW(path.c_str(), &findData);
	if(INVALID_HANDLE_VALUE == hFind) return;
	
	while(true) {
		sFile.clear();
		sFile.append(root);
		sFile.append(L"\\");
		sFile.append(findData.cFileName);
		if(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) { 
			if(findData.cFileName[0] != '.') {
				find(sFile.c_str(), ++depth);
			}
		} 
		else {
			for (size_t i = 0; i < _exts.size(); i++) {
				if (str_endswith(sFile, _exts[i]))
					_files.push_back(sFile);
			}
		}
		
		if(!::FindNextFileW(hFind, &findData)) break; 
	}
}

vector<wstring> FileWalker::getResults() {
	return _files;
}