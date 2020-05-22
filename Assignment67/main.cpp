#include <iostream>
#include "String.h"
#include "Calculator.h"

using namespace std;	

int main(int argc, char* argv[])
{
	char expr[1000];
	Calculator c = Calculator();
		
	cout << "수식을 입력하시오 : ";
	cin.getline(expr, 1000);

	c.setExpression(expr);

	String posfix = c.getPostFix();
	cout << "후위표기식 : " << posfix << "결과값 : " << c.getValue() << endl;
	
	return 0;
}