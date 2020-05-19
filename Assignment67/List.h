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
	int removeAt(int index);
	int removeItem(T itm);
	void print();
	void concat(List& list);
	int length();
};