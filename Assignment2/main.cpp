#include <iostream>
#include "Rectangle.h"

int main(int argc, char* argv[])
{
	Rectangle rect1, rect2, rect3;
	rect1.read();
	rect2.read();
	cout << "Rect1 Area:" << rect1.getArea() << endl;
	cout << "Rect2 Area:" << rect2.getArea() << endl;
	rect3 = rect1 + rect2;
	cout << rect3;
	cout << (rect1 == rect2) << endl;
	rect3 = rect1 / rect2;
	cout << rect3;
	cout << "Rect3 print function" << endl;
	rect3.print();
	return 0;
}