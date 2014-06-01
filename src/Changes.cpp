#include "Changes.h"

Changes :: Changes(string c, char s)
: change(c), symbol(s){}

Changes :: Changes(string c, char s, string t)
: change(c), symbol(s), teste(t){}


string Changes :: getChange(){
	string temp;
	temp += teste;
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
