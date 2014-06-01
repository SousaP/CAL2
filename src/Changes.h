#ifndef CHANGES_H_
#define CHANGES_H_

#include <string>
#include <iostream>

using namespace std;

class Changes{
private:
	string change;
	char symbol;
	string line;
public:
	Changes(string c, char s);
	Changes(string c, char s, string t);
	string getChange();
	string Change();
	char getSymbol();
};
#endif
