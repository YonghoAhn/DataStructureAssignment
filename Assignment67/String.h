#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* buffer;
	int length;
	int size;

	String(int m);

public:
	String();
	String(const String &s);
	String(char* init, int m); //길이 m짜리 init 스트링
	~String();
	String Concat(String s);
	String& operator=(const String& s);
	bool operator== (String t);
	bool operator! ();
	char* getBuffer();
	int Length();
	String Substr(int i, int j);
	int Find(String pattern);
	void Print();
	bool isDigit();
	int toInt32();
	friend ostream& operator<<(ostream& os, String& s);
};