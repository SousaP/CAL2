#include "Changes.h"

Changes :: Changes(string c, char s)
: change(c), symbol(s), line(""){}

Changes :: Changes(string c, char s, string t)
: change(c), symbol(s), line(t){}


string Changes :: getChange(){
	string temp;
	temp += line;
	temp += " ";
	temp += symbol;
	temp += " ";
	temp += change;
	return temp;
}

string Changes :: Change(){
	return change;
}
char Changes ::getSymbol(){
	return symbol;
}
