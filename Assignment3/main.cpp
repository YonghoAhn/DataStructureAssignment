#include <iostream>
#include "List.h"
#include "OrderedList.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "======================== List START ========================" << endl;
	List list;
	for (int i = 0; i < 20; i++)
		list.addItem(i);
	List list2;
	for (int i = 0; i < 20; i++)
		list2.addItem(i);
	list.print();
	list2.print();
	cout << "======================== List InsertItem ========================" << endl;
	list.insertItem(8, 100);
	list.print();
	cout << "======================== List RemoveAt(5) ========================" << endl;
	list.removeAt(5);
	list.print();
	cout << "======================== List RemoveItem(1) ========================" << endl;
	list.removeItem(1);
	list.print();
	list2.print();
	cout << "======================== List concat ========================" << endl;
	list.concat(list2);
	list.print();

	cout << "======================== OrderedList START ========================" << endl;
	OrderedList olist;
	for (int i = 0; i < 20; i++)
		olist.addItem(i);
	OrderedList olist2;
	for (int i = 0; i < 20; i++)
		olist2.addItem(i);
	cout << "======================== OrderedList RemoveAt(5) ========================" << endl;
	olist.removeAt(5);
	olist.print();
	cout << "======================== OrderedList RemoveItem(1) ========================" << endl;
	olist.removeItem(1);
	olist.print();
	olist2.print();
	cout << "======================== OrderedList concat ========================" << endl;
	olist.concat(olist2);
	olist.print();
	return 0;
}