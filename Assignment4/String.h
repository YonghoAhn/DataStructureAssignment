#pragma once
class String
{
private:
	char* buffer;
	int length;
	int size;
	

	String(int m);

public:
	String();
	String(String& s);
	String(char* init, int m); //���� m¥�� init ��Ʈ��
	~String();
	String Concat(String s);
	String& operator=(const String& s);
	bool operator== (String t);
	bool operator! ();

	int Length();
	String Substr(int i, int j);
	int Find(String pattern);
	void Print();
};