#include "Rectangle.h"

void Rectangle::read()
{
	cout << "Input Width" << endl;
	cin >> width;
	cout << "Input Height" << endl;
	cin >> height;
}

void Rectangle::print()
{
	cout << "Width: " << width << " Height: " << height << endl;
}
