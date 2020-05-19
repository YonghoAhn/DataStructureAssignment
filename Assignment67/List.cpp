#include "List.h"
#include <iostream>

using namespace std;

template <class T>
List<T>::List()
{
	itemCount = 0;
	size = 5;
	items = new T[size];
	cout << "List Constructor" << endl;
}

template <class T>
List<T>::~List()
{
	delete[] items;
	cout << "List Destructor" << endl;
}

template <class T>
T List<T>::getItem(int index)
{
	if (index < itemCount)
		return items[index];
	else
		return -99999;
}

template <class T>
void List<T>::addItem(T itm)
{
	if (itemCount < size)
	{
		items[itemCount++] = itm;
	}
	else
	{
		T* newData = new T[size * 2];
		for (int i = 0; i < itemCount; i++)
			newData[i] = items[i];
		newData[itemCount++] = itm;
		delete[] items;
		items = newData;
		size *= 2;
	}
}

template <class T>
void List<T>::insertItem(int index, T itm)
{
	if (index > itemCount)
		return;
	int i = 0;
	if (!(itemCount < size))
		size = size + 1;

	T* temp = new T[size];
	for (i = 0; i < index; i++)
		temp[i] = items[i];
	temp[index] = itm;
	for (i = index + 1; i <= itemCount; i++)
		temp[i] = items[i - 1];
	delete[] items;
	items = temp;
	itemCount++;
}

template <class T>
int List<T>::removeAt(int index)
{
	if (index >= itemCount)
		return -99999;

	int i = 0;
	T tmp = items[index];
	for (i = index + 1; i < itemCount; i++)
		items[i - 1] = items[i];
	items[i - 1] = 0;
	itemCount--;
	return tmp;
}

template <class T>
int List<T>::removeItem(T itm)
{
	for (int i = 0; i < itemCount; i++)
		if (items[i] == itm)
		{
			removeAt(i);
			return i;
		}
	return -99999;
}

template <class T>
void List<T>::print()
{
	for (int i = 0; i < itemCount; i++)
	{
		cout << "item " << i << ": " << items[i] << " ";
	}
	cout << endl;
}

template <class T>
void List<T>::concat(List& list)
{
	int i = 0, j = 0;
	T* tmp = new T[list.size + size];
	for (i; i < itemCount; i++)
		tmp[i] = items[i];
	for (i; j < list.itemCount; j++)
		tmp[i++] = list.items[j];
	delete[] items;
	items = tmp;
	size += list.size;
	itemCount += list.itemCount;
}

template<class T>
int List<T>::length()
{
	return itemCount;
}
	