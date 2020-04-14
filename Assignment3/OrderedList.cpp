#include "OrderedList.h"

void OrderedList::concat(OrderedList& olist)
{
	int i = 0, j = 0, k =0;
	int* tmp = new int[olist.size + size];
	while (i < itemCount && j < olist.itemCount)
	{
		tmp[k++] = (items[i] <= olist.items[j]) ? items[i++] : olist.items[j++];
	}
	if (i < itemCount)
	{
		for (i; i < itemCount; i++)
			tmp[k++] = items[i];
	}
	else {
		for (j; j < olist.itemCount; j++)
			tmp[k++] = olist.items[j];
	}
	delete[] items;
	items = tmp;
	size += olist.size;
	itemCount += olist.itemCount;
}

void OrderedList::addItem(int itm)
{
	if (itemCount < size)
	{
		int pos;
		for (pos = 0; pos < itemCount; pos++)
			if (items[pos] > itm)
				break;
		if (pos == itemCount)
			items[itemCount++] = itm;
		else
			List::insertItem(pos, itm);
	}
	else
	{
		int* newData = new int[size+1];
		int i = 0;
		for (i = 0; i < itemCount; i++)
		{
			if (items[i] > itm)
				break;
			newData[i] = items[i];
		}
		newData[i] = itm;
		if(i < itemCount)
			for (++i; i <= itemCount; i++)
				newData[i] = items[i - 1];
		delete[] items;
		items = newData;
		itemCount++;
		size+=1;
	}
}

void OrderedList::print()
{
	List::print();
}

int OrderedList::removeAt(int index)
{
	return List::removeAt(index);
}

int OrderedList::removeItem(int itm)
{
	return List::removeItem(itm);
}

int OrderedList::getItem(int index)
{
	return List::getItem(index);
}
