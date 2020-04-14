#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
	itemCount = 0;
	size = 5;
	items = new int[size];
	cout << "List Constructor" << endl;
}

List::~List()
{
	delete[] items;
	cout << "List Destructor" << endl;
}

int List::getItem(int index)
{
	if (index < itemCount)
		return items[index];
	else
		return -99999;
}

void List::addItem(int itm)
{
	if (itemCount < size)
	{
		items[itemCount++] = itm;
	}
	else
	{
		int* newData = new int[size * 2];
		for (int i = 0; i < itemCount; i++)
			newData[i] = items[i];
		newData[itemCount++] = itm;
		delete[] items;
		items = newData;
		size *= 2;
	}
}

void List::insertItem(int index, int itm)
{
	if (index > itemCount)
		return;
	int i = 0;
	if (!(itemCount < size))
		size = size + 1;

	int* temp = new int[size];
	for (i = 0; i < index; i++)
		temp[i] = items[i];
	temp[index] = itm;
	for (i=index+1; i <= itemCount; i++)
		temp[i] = items[i - 1];
	delete[] items;
	items = temp;
	itemCount++;
}

int List::removeAt(int index)
{
	if (index >= itemCount)
		return -99999;

	int i = 0;
	int tmp = items[index];
	for (i = index+1; i < itemCount; i++)
		items[i - 1] = items[i];
	items[i-1] = 0;
	itemCount--;
	return tmp;
}

int List::removeItem(int itm)
{
	for (int i = 0; i < itemCount; i++)
		if (items[i] == itm)
		{
			removeAt(i);
			return i;
		}
	return -99999;
}

void List::print()
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << "item " << i << ": " << items[i] << " ";
	}
	cout << endl;
}

void List::concat(List& list)
{
	int i = 0, j = 0;
	int* tmp = new int[list.size + size];
	for (i; i < itemCount; i++)
		tmp[i] = items[i];
	for (i; j < list.itemCount; j++)
		tmp[i++] = list.items[j];
	delete[] items;
	items = tmp;
	size += list.size;
	itemCount += list.itemCount;
}
