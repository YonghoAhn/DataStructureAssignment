#include "Rectangle.h"

void Rectangle::read()
{
	cout << "Input Point X" << endl;
	cin >> x;
	cout << "Input Point Y" << endl;
	cin >> y;
	cout << "Input Width" << endl;
	cin >> width;
	cout << "Input Height" << endl;
	cin >> height;
	cout << "Generated Rectangle (X:" << x << " Y:" << y << " Width:" << width << " Height:" << height << endl;
}

void Rectangle::print()
{
	cout << "X:" << x << " Y:" << y << endl << "Width: " << width << " Height: " << height << endl;
}

int Rectangle::getArea()
{
	return width * height;
}

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rectangle::~Rectangle()
{
	cout << "Destroyer" << endl;
}

Rectangle Rectangle::operator + (Rectangle& r)
{
	return Rectangle((x <= r.x) ? x:r.x,
					 (y <= r.y) ? y: r.y,
					 (x+width >= r.x+r.width) ? (x+width - ((x <= r.x) ? x:r.x)) : (r.x + r.width - ((x <= r.x) ? x : r.x)),
					 (y + height >= r.y + r.height) ? (y + height - ((y <= r.y) ? y : r.y)) : (r.y + r.height - ((y <= r.y) ? y : r.y)));
}

Rectangle Rectangle::operator/(Rectangle& r)
{
	return Rectangle(!(x <= r.x) ? x : r.x,
					 !(y <= r.y) ? y : r.y,
					 !(x + width >= r.x + r.width) ? (x + width - (!(x <= r.x) ? x : r.x)) : (r.x + r.width - (!(x <= r.x) ? x : r.x)),
					 !(y + height >= r.y + r.height) ? (y + height - (!(y <= r.y) ? y : r.y)) : (r.y + r.height - (!(y <= r.y) ? y : r.y)));
}

bool Rectangle::operator==(Rectangle& r)	
{
	return ((x == r.x) && (y == r.y) && (width == r.width) && (height == r.height));
}

ostream& operator<<(ostream& os, const Rectangle& r)
{
	os << "X:" << r.x << " Y:" << r.y << endl << "Width: " << r.width << " Height: " << r.height << endl;
	return os;
}
