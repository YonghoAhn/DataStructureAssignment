#include <iostream>
#include "String.h"
#include "Calculator.h"

using namespace std;	

int main(int argc, char* argv[])
{
	char expr[1000];
	Calculator c = Calculator();
		
	cout << "������ �Է��Ͻÿ� : ";
	cin.getline(expr, 1000);

	c.setExpression(expr);

	String posfix = c.getPostFix();
	cout << "����ǥ��� : " << posfix << "����� : " << c.getValue() << endl;
	
	return 0;
}