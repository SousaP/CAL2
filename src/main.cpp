#include "FileRevision.h"
#include <iostream>
string computeLCS(string s, string t) {

	if (s.size() > t.size())
		swap(s, t);

	unsigned int n = s.size();
	unsigned int m = t.size();

	vector<vector<unsigned int> > L(n + 1, vector<unsigned int>(m + 1));

	for (unsigned long int i = 0; i < s.size(); i++)
		for (unsigned long int j = 0; j < t.size(); j++)
			L[i][j] = 0;
	unsigned long int z = 0;

	string ret;

	for (unsigned long int i = 0; i < s.size(); i++) {
		for (unsigned long int j = 0; j < t.size(); j++) {
			if (s[i] == t[j]) {
				if (i == 0 || j == 0) {
					L[i][j] = 1;
				} else {
					L[i][j] = L[i - 1][j - 1] + 1;
				}

				if (L[i][j] > z) {
					z = L[i][j];
					ret = s.substr(i - z + 1, z);
				} else if (L[i][j] == z) {
					ret += s.substr(i - z + 1, z);
				} else {
					L[i][j] = 0;
				}
			}
		}
	}
	return ret;
}

void searchString(string s1, string s2) {

	string temp1, temp2;
	string LCS = computeLCS(s1, s2);
	unsigned int pos1, pos2;
	if (LCS.size() == 0) {
		if (s1.size() != 0)
			cout << "-" << s1 << "-";
		if (s2.size() != 0)
			cout << "+" << s2 << "+";
		return;
	} else if (LCS.size() == s1.size()) {
		if (s1.size() == s2.size()) {
			cout << ">" << LCS << "<";
			return;
		}
		pos2 = s2.find(LCS);
		if (pos2 == 0) {
			temp2 = s2;
			cout << ">" << LCS << "<";
			temp2.erase(0, LCS.size());
			if (temp2.size() != 0)
				cout << "+" << temp2 << "+";
		} else {
			temp1.assign(s2, 0, pos2);
			temp2.assign(s2, pos2 + LCS.size(), s2.size() - LCS.size());
			if (temp1.size() != 0)
				cout << "+" << temp1 << "+";
			cout << ">" << LCS << "<";
			if (temp2.size() != 0)
				cout << "+" << temp2 << "+";
		}
		return;
	}

	pos1 = s1.find(LCS);
	pos2 = s2.find(LCS);

	temp1.assign(s1, 0, pos1);
	temp2.assign(s2, 0, pos2);
	searchString(temp1, temp2);

	cout << ">" << LCS << "<";

	temp1.assign(s1, pos1 + LCS.size(), s1.size() - LCS.size());
	temp2.assign(s2, pos2 + LCS.size(), s2.size() - LCS.size());

	searchString(temp1, temp2);

}

void CompareFiles(Files F1, Files F2) {
	vector<Changes> changes;

	string File1 = F1.GetText();
	string File2 = F2.GetText();
	string LCS = computeLCS(File1, File2);
	if (LCS.size() == 0) {
		cout << "Ficheiros completamente diferentes";
		return;
	}

	searchString(File1, File2);
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

	cout << "LCS: " << computeLCS(s1, s2) << endl;

}

int main() {
	string escolha = "";

	while (escolha != "sair" && escolha != "Sair") {
		cout << "\n1. Strings\n2. Files\n";
		cin >> escolha;

		if (escolha == "1" || escolha == "Srings" || escolha == "srings")
			MenuStrings();
		else if (escolha == "2" || escolha == "Files" || escolha == "files")
			MenuFiles();

	}

	return 0;
}
