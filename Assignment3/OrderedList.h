#pragma once
#include "List.h"

class OrderedList : List
{
public:
	void concat(OrderedList& olist);
	virtual void addItem(int itm);
	void print();
	int removeAt(int index);
	int removeItem(int itm);
	int getItem(int index);
};