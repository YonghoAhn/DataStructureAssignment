#include "String.h"
#include <iostream>
#include <cctype>

using namespace std;

String::String(int m)
{
	size = m;
	buffer = new char[m];
	length = 0;
}

String::String() : String(10)
{}

String::String(const String &s) : String(s.length + 1)
{
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[s.length] = '\0';
	length = s.length;
}

String::String(char* init, int m) : String(m + 1)
{
	for (int i = 0; i < m; i++)
		buffer[i] = init[i];
	buffer[m] = '\0';
	length = m;
}

String::~String()
{
	delete[] buffer;
}

String& String::operator=(const String& s)
{
	delete[] buffer;
	buffer = new char[s.length + 1];
	for (int i = 0; i < s.length; i++)
		buffer[i] = s.buffer[i];
	buffer[s.length] = '\0';
	length = s.length;
	return *this;
}

bool String::operator==(String t)
{
	if (t.length != length) return false;
	for (int i = 0; i < length; i++)
		if (t.buffer[i] != buffer[i]) return false;
	return true;
}

bool String::operator!()
{
	for (int i = 0; i < length; i++)
		if (buffer[i] != ' ') return false;
	return true;
}

char* String::getBuffer()
{
	return buffer;
}

String String::Concat(String t)
{
	String result(length + t.length + 1);
	for (int i = 0; i < length; i++)
		result.buffer[i] = buffer[i];
	for (int i = 0; i < t.length; i++)
		result.buffer[length + i] = t.buffer[i];

	result.buffer[length + t.length] = '\0';
	result.length = length + t.length;
	return result;
}

String String::Substr(int i, int j)
{
	int len = j - i + 1;
	char* ch = new char[len + 1];
	for (int k = 0; k < len; k++)
		ch[k] = buffer[i++];
	ch[j] = '\0';
	String s(ch, len);
	return s;
}

int String::Find(String pattern)
{
	for (int start = 0; start <= Length() - pattern.Length(); start++)
		for (int j = 0; j < pattern.Length() && buffer[start + j] == pattern.buffer[j]; j++)
			if (j == pattern.Length() - 1) return start;
	return -1;
}

void String::Print()
{
	cout << buffer << endl;
}

bool String::isDigit()
{
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(buffer[i])) return false;
	}
	return true;
}

int String::Length()
{
	return length;
}

ostream& operator<<(ostream& os, String& s)
{
	os << s.getBuffer() << endl;
	return os;
}
