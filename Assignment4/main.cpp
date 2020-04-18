#include <iostream>
#include "String.h"
using namespace std;

int main(int argc, char* argv[])
{
	String s1((char *)"asdf",4);
	String s2((char*)"asdf", 4);
	String s3;
	String s4((char*)"fas", 3);
	s3 = s1.Concat(s2);
	s1.Print();
	s2.Print();
	s3.Print();
	if (s1 == s2) cout << "same" << endl; else cout << "not same" << endl;
	if (!s1) cout << "empty" << endl; else cout << "not empty" << endl;
	cout << s3.Length() << endl;
	s3.Substr(1, 3).Print();
	s3.Print();
	cout << s3.Find(s4) << endl;
	return 0;
} 
