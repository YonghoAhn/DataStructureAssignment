#pragma once
template <class T>
class List
{
protected:
	T* items;
	int itemCount = 0;
	int size = 5;
public:
	List();
	~List();
	T getItem(int index);
	virtual void addItem(T itm);
	void insertItem(int index, T itm);
	T removeAt(int index);
	int removeItem(T itm);
	void print();
	void concat(List& list);
	int length();
	List& operator=(const List& list);
};

using namespace std;

template <class T>
List<T>::List()
{
	itemCount = 0;
	size = 5;
	items = new T[size];
}

template <class T>
List<T>::~List()
{
	delete[] items;
}

template <class T>
T List<T>::getItem(int index)
{
	if (index < itemCount)
		return items[index];
	else
		throw "Index out";
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
	//delete[] items;
	items = temp;
	itemCount++;
}

template <class T>
T List<T>::removeAt(int index)
{
	if (index >= itemCount)
		throw "Error";

	int i = 0;
	T tmp = items[index];
	for (i = index + 1; i < itemCount; i++)
		items[i - 1] = items[i];
	items[i - 1].~T();
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

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
	delete[] items;
	items = new T[list.size];
	for (int i = 0; i < list.itemCount; i++)
		items[i] = list.items[i];
	this->size = list.size;
	this->itemCount = list.itemCount;
	return *this;
}
