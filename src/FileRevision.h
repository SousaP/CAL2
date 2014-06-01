#ifndef FILEREVISION_H_
#define FILEREVISION_H_

#include <string>
#include <iostream>
#include "Changes.h"
#include "Files.h"

using namespace std;

class FileRevision{
private:
	Files File1;
	Files File2;
	vector <Changes> Differences;
public:
	FileRevision(Files F1,Files F2,vector <Changes> Diff);
	FileRevision(Files F1, Files F2);
	Files getFile1();
	Files getFile2();
	vector <Changes> getDiff();
	void addDifferences(Changes c);
	void CreatCompareFile();
	void SaveDiff();
};

string computeLCS(string s, string t);

bool compareString(string s, string t);


#endif
