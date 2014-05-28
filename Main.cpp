#include<vector>
#include<string>
#include<iostream>

using namespace std;

/* Dynamic Programming implementation of LCS problem */
#include<stdio.h>
#include<stdlib.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Driver program to test above function */

//printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );


unsigned int levenshtein_distance(string &s1, string & s2) {
	const size_t len1 = s1.size(), len2 = s2.size();
	vector<unsigned int> col(len2+1), prevCol(len2+1);

	for (unsigned int i = 0; i < prevCol.size(); i++)
		prevCol[i] = i;
	for (unsigned int i = 0; i < len1; i++) {
		col[0] = i+1;
		for (unsigned int j = 0; j < len2; j++)
			col[j+1] = min( min(prevCol[1 + j] + 1, col[j] + 1),
								prevCol[j] + (s1[i]==s2[j] ? 0 : 1) );
		col.swap(prevCol);
	}
	return prevCol[len2];
}


int main(){
	vector< string> v1;
	vector< string> v2;
	string s1 = "Sera que isto funciona?";
	string s2 = "Sera que isto funciona?";
	string s3 = "Sera que isto funciona?";
	string s4 = "Tera que isto funciona?";
	string s5 = "fdsjhfsdhfjksdhlfjslfjlkdslfhsldkjflksfdljfjlsfl";
	string s6 = "fdjkhfdkjhfdifjkbdsyfghewbfsdfhksdgkjhsfkfgkhfskfsffsu";
	cout << "Presenting edit distance between strings:" << endl;
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s5);
	v2.push_back(s2);
	v2.push_back(s4);
	v2.push_back(s6);
	int distance = 0;
	for(int i = 0; i < v1.size(); i++){
		distance += levenshtein_distance(v1[i], v2[i]);
	}
	cout << distance << endl;

	cout << "Length of LCS is " << lcs( v1[0], v2[0], (v1[0]).length(), (v2[0]).length() ) << "    Lenght of stings: " << v1[0].length() << endl;
	return 0;
}
