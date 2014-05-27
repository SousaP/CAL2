#include "Changes.h"

Changes :: Changes(string c, char s)
: change(c), symbol(s){}

string Changes :: getChange(){
	string temp;
	temp += symbol;
	temp += " ";
	temp += change;
	temp += " ";
	temp += symbol;
	return temp;
}

string Changes :: Change(){
	return change;
}
char Changes ::getSymbol(){
	return symbol;
}
