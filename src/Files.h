#ifndef FILES_H_
#define FILES_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Files{
private:
	string name;
	vector<string> lines;
public:
	Files();
	Files(string n, bool &good);
	Files(string n, vector<string> l);
	string getName();
	vector<string> getLines();
	string GetText();
};

#endif
