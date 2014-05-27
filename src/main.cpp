#include "FileRevision.h"




int main(){
	bool good = true;
	string f1, f2;
	Files File1, File2;

	cout << "||Comparacao de ficheiros||";

	do{
	cout << "\nFile 1:  ";
	cin >> f1;
	File1 = Files(f1,good);
	}while(!good);

	do{
	cout << "\nFile 2:  ";
	cin >> f2;
	File2 = Files(f2,good);
	}while(!good);



	return 0;
}
