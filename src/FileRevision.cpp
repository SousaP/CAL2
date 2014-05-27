#include "FileRevision.h"


FileRevision :: FileRevision(Files F1,Files F2,vector <Changes> Diff)
: File1(F1), File2(F2), Differences(Diff){}

FileRevision :: FileRevision(Files F1, Files F2)
: File1(F1), File2(F2){}


Files FileRevision :: getFile1(){
	return File1;
}

Files FileRevision :: getFile2(){
	return File2;
}

vector <Changes> FileRevision ::getDiff(){
	return Differences;
}
