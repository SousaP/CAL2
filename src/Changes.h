#ifndef CHANGES_H_
#define CHANGES_H_

#include <string>
#include <iostream>

using namespace std;

class Changes{
private:
	string change;
	char symbol;
public:
	Changes(string c, char s);
	string getChange();
	string Change();
	char getSymbol();
};




#endif
