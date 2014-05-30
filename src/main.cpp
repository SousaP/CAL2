#include "FileRevision.h"
#include <iostream>
int lcs(string X, string Y, int m, int n) {
	int L[m + 1][n + 1];
	int i, j;

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	 that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return L[m][n];
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

}

void MenuStrings() {
	cout << "||Comparacao de Strings||\n";

	string s1, s2;

	cin.ignore();
	cout << "String1: ";
	getline (cin,s1);

	cout << "String2: ";
	getline (cin,s2);

	cout << "Length of LCS is " << lcs(s1, s2, s1.size(), s2.size())
			<< "    Lenght of stings: " << s1.size() << endl;

}

int main() {
	string escolha = "";

	while (escolha != "sair" && escolha != "Sair") {
		cout << "1. Strings\n2. Files\n";
		cin >> escolha;

		if (escolha == "1" || escolha == "Srings" || escolha == "srings")
			MenuStrings();
		else if (escolha == "2" || escolha == "Files" || escolha == "files")
			MenuFiles();
		else
			cout << "Bad input\n";

	}

	return 0;
}
