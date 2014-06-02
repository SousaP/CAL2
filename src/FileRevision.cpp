#include "FileRevision.h"
#include <string>
#include <sstream>
FileRevision::FileRevision(Files F1, Files F2, vector<Changes> Diff) :
		File1(F1), File2(F2), Differences(Diff) {
}

FileRevision::FileRevision(Files F1, Files F2) :
		File1(F1), File2(F2) {
}

Files FileRevision::getFile1() {
	return File1;
}

Files FileRevision::getFile2() {
	return File2;
}

vector<Changes> FileRevision::getDiff() {
	return Differences;
}

void FileRevision::addDifferences(Changes c) {
	Differences.push_back(c);
}

string LCS(string s, string t) {

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

unsigned int levenshtein_distance(string &s1, string & s2) {
	const size_t len1 = s1.size(), len2 = s2.size();
		vector<vector<unsigned int> > d(len1 + 1, vector<unsigned int>(len2 + 1));

		d[0][0] = 0;
		for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
		for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

		for(unsigned int i = 1; i <= len1; ++i)
			for(unsigned int j = 1; j <= len2; ++j)

	                      d[i][j] = min( min(d[i - 1][j] + 1,d[i][j - 1] + 1),
	                                          d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) );
		return d[len1][len2];
}

bool compareString(string s, string t) {
	unsigned int comp = levenshtein_distance(s, t);
	if (comp <= s.size() / 3 || comp <= t.size() / 3)
		return true;

	return false;
}

void FileRevision::CreatCompareFile() {

	//vector <Changes> Differences;
	vector<string> L1, L2;
	L1 = File1.getLines();
	L2 = File2.getLines();

	bool encontrou = false;
	int cont = 0;
	int cont2 = 0;
	stringstream nrline;
	string line;
	for (unsigned int i = 0; i < L2.size(); i++) {
		for (unsigned int d = cont; d < L1.size(); d++) {
			if (L2[i] == L1[d]) {
				Differences.push_back(Changes(L2[i], '>'));
				encontrou = true;
				cont++;
				break;
			} else if (compareString(L2[i], L1[d])) {
				line = "FA";
				nrline << (d + 1);
				line += nrline.str();
				nrline.str("");
				nrline.clear();
				Differences.push_back(Changes(L1[d], '~', line));
				line = "FN";
				nrline << (i + 1);
				line += nrline.str();
				nrline.str("");
				nrline.clear();
				Differences.push_back(Changes(L2[i], '~', line));
				encontrou = true;
				cont++;
				break;
			}
		}
		if (!encontrou) {
			line = "FN";
			nrline << (i + 1);
			line += nrline.str();
			nrline.str("");
			nrline.clear();
			Differences.push_back(Changes(L2[i], '+', line));
			cont2++;
		}

		encontrou = false;
	}

	int pos = 0;

	for (unsigned int d = 0; d < L1.size(); d++) {
		for (unsigned int i = 0; i < d + cont2; i++) {
			if (L2[i] == L1[d]) {
				encontrou = true;
				break;
			} else if (compareString(L2[i], L1[d])) {
				encontrou = true;
				pos++;
				break;
			}
		}
		if (!encontrou) {
			line = "FA";
			nrline << (d + 1);
			line += nrline.str();
			nrline.str("");
			nrline.clear();
			Differences.insert(Differences.begin() + d + pos,
					Changes(L1[d], '-', line));
		}

		encontrou = false;
	}

	SaveDiff();
}
void FileRevision::SaveDiff() {
	string filename = "Compare.txt";
	ofstream myfile(filename.c_str());

	for (unsigned int i = 0; i < Differences.size(); i++)
		myfile << Differences[i].getChange() << endl;

	myfile.close();
}

void FileRevision:: showDiff(){
	for(unsigned int i = 0; i < Differences.size(); i++)
			cout << Differences[i].getChange() << endl;
}

