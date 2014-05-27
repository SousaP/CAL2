#include "Files.h"

Files :: Files(){}


Files::Files(string n, bool &good) :
		name(n) {
	string newLine;

	ifstream myfile(n.c_str());

	if (myfile.good()){
		while (!myfile.eof()) {

			getline(myfile, newLine);
			if (newLine != "") {
				lines.push_back(newLine);
			}

			newLine = "";
		}
		myfile.close();
	}
	else
		good = false;
}
Files::Files(string n, vector<string> l) :
		name(n), lines(l) {
}

string Files::getName() {
	return name;
}

vector<string> Files::getLines() {
	return lines;
}
