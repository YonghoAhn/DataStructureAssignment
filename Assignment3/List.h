#pragma once

class List
{
protected:
	int* items;
	int itemCount = 0;
	int size = 5;
public:
	List();
	~List();
	int getItem(int index);
	virtual void addItem(int itm);
	void insertItem(int index, int itm);
	int removeAt(int index);
	int removeItem(int itm);
	void print();
	void concat(List& list);
};