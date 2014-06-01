#include "Files.h"

Files::Files() {
}

Files::Files(string n, bool &good) :
		name(n) {
	string newLine;

	ifstream myfile(n.c_str());

	if (myfile.good()) {
		while (!myfile.eof()) {

			getline(myfile, newLine);
				lines.push_back(newLine);
		}
		myfile.close();
		good = true;
	} else
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

string Files::GetText() {
	string retorno = "";
	for (int i = 0; i < lines.size(); i++) {
		retorno += lines[i];
		if(i != lines.size()-1)
		retorno += "\n";
	}

	return retorno;
}
