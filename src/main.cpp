#include "FileRevision.h"
#include <iostream>

void searchString(string s1, string s2) {

	string temp1, temp2;
	string strLCS = LCS(s1, s2);
	unsigned int pos1, pos2;
	if (strLCS.size() == 0) {
		if (s1.size() != 0)
			cout << "-" << s1 << "-";
		if (s2.size() != 0)
			cout << "+" << s2 << "+";
		return;
	} else if (strLCS.size() == s1.size()) {
		if (s1.size() == s2.size()) {
			cout << ">" << strLCS << "<";
			return;
		}
		pos2 = s2.find(strLCS);
		if (pos2 == 0) {
			temp2 = s2;
			cout << ">" << strLCS << "<";
			temp2.erase(0, strLCS.size());
			if (temp2.size() != 0)
				cout << "+" << temp2 << "+";
		} else {
			temp1.assign(s2, 0, pos2);
			temp2.assign(s2, pos2 + strLCS.size(), s2.size() - strLCS.size());
			if (temp1.size() != 0)
				cout << "+" << temp1 << "+";
			cout << ">" << strLCS << "<";
			if (temp2.size() != 0)
				cout << "+" << temp2 << "+";
		}
		return;
	}

	pos1 = s1.find(strLCS);
	pos2 = s2.find(strLCS);

	temp1.assign(s1, 0, pos1);
	temp2.assign(s2, 0, pos2);
	searchString(temp1, temp2);

	cout << ">" << strLCS << "<";

	temp1.assign(s1, pos1 + strLCS.size(), s1.size() - strLCS.size());
	temp2.assign(s2, pos2 + strLCS.size(), s2.size() - strLCS.size());

	searchString(temp1, temp2);

}

void CompareFiles(Files F1, Files F2) {

	vector<Changes> changes;

	string File1 = F1.GetText();
	string File2 = F2.GetText();

	FileRevision F(F1,F2);
	F.CreatCompareFile();
}

void MenuFiles() {
	bool good;
	string f1, f2;
	Files File1, File2;

	cout << "||Comparacao de ficheiros||\n";

	do {
		cout << "\nFile 1:  ";
		cin >> f1;
		File1 = Files(f1, good);
	} while (!good);

	do {
		cout << "\nFile 2:  ";
		cin >> f2;
		File2 = Files(f2, good);
	} while (!good);
	CompareFiles(File1, File2);
}

void MenuStrings() {
	cout << "||Comparacao de Strings||\n";

	string s1, s2;

	cin.ignore();
	cout << "String1: ";
	getline(cin, s1);

	cout << "String2: ";
	getline(cin, s2);

	cout << "LCS: " << LCS(s1, s2) << endl;

}

int main() {
	string escolha = "";

	while (escolha != "sair" && escolha != "Sair" && escolha != "3") {
		cout << "\n1. Strings\n2. Files\n3. Sair\n";
		cin >> escolha;

		if (escolha == "1" || escolha == "Srings" || escolha == "srings")
			MenuStrings();
		else if (escolha == "2" || escolha == "Files" || escolha == "files")
			MenuFiles();

	}

	return 0;
}
