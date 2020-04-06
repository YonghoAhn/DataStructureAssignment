#pragma once
#include <iostream>
using namespace std;

class Rectangle {
private:
	int x, y;
	int width;
	int height;
public:
	void read();
	void print();
	int getArea();
	Rectangle();
	Rectangle(int x, int y, int width, int height);
	~Rectangle();
	Rectangle operator+(Rectangle& r);
	Rectangle operator/(Rectangle& r);
	bool operator==(Rectangle& r);
	friend ostream& operator<<(ostream& os, const Rectangle& r);
};