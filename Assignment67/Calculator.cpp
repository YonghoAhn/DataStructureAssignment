#include "Calculator.h"
#include <string.h>
#include "Stack.h"
#include "List.h"
#pragma warning(disable : 4996)

String Calculator::makePostFix()
{
	Stack<String> stackOperator(100);
	List<String> token;

	String leftBracket((char*)"(", 1);
	String rightBracket((char*)")", 1);
	String plus((char*)"+", 1);
	String minus((char*)"-", 1);
	String multiply((char*)"*", 1);
	String divide((char*)"/", 1);

	String postf((char *)"", 1);
	for (int idx = 0; idx < tokens.length(); idx++) {
		String s = tokens.getItem(idx);

		if (s.isDigit())
		{
			token.addItem(s);
		}
		else
		{
			if (s == leftBracket)
			{
				stackOperator.Push(s);
			}
			else if (s == rightBracket)
			{
				while (!stackOperator.IsEmpty())
				{
					String op = *stackOperator.Top();
					stackOperator.Pop();
					char ch = getOpCharacter(op);
					if (ch != '(') token.addItem(op);
					else {
						break;
					};
				}

			}
			else if (s == plus || s == minus || s == divide || s == multiply)
			{
				while ((!stackOperator.IsEmpty()) && getOpPriority(getOpCharacter(*stackOperator.Top()), getOpCharacter(s)))
				{
					token.addItem(*stackOperator.Top());
					stackOperator.Pop();
				}
				stackOperator.Push(s);
			}

		}
	}
	while (!stackOperator.IsEmpty())
	{
		token.addItem(*stackOperator.Top());
		stackOperator.Pop();
	}
	for (int i = 0; i < token.length(); i++)
	{
		postfix = postfix.Concat(token.getItem(i));
	}
	tokens = token;
	return postf;
}

int Calculator::evaluation()
{
	for (int i = 0; i < tokens.length(); i++)
	{
		if (!tokens.getItem(i).isDigit())
		{
			int operand1 = tokens.getItem(i - 2).toInt32();
			int operand2 = tokens.getItem(i - 1).toInt32();
			char op = getOpCharacter(tokens.getItem(i));
			tokens.removeAt(i - 2);
			tokens.removeAt(i - 2);
			tokens.removeAt(i - 2);
			int result = 0;
			switch (op)
			{
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					result = operand1 / operand2;
					break;
			}
			char buff[256];
			sprintf(buff, "%d", result);
			String str(buff, strlen(buff));
			tokens.insertItem(i-2, str);
			i = 0;
		}
	}
	value = tokens.getItem(0).toInt32();
	return 0;
}

int Calculator::getOpPriority(const char op)
{
	switch (op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	return -1;
}

bool Calculator::getOpPriority(const char op1, const char op2)
{
	if (getOpPriority(op1) > getOpPriority(op2))
		return true;
	else
		return false;
}

char Calculator::getOpCharacter(String s)
{
	String plus((char*)"+", 1);
	String minus((char*)"-", 1);
	String multiply((char*)"*", 1);
	String divide((char*)"/", 1);
	String leftBracket((char*)"(", 1);
	String rightBracket((char*)")", 1);
	if (s == plus) return '+';
	if (s == minus) return '-';
	if (s == multiply) return '*';
	if (s == divide) return '/';
	if (s == leftBracket) return '(';
	if (s == rightBracket) return ')';
	return 0;
}

String Calculator::itos(int value)
{
	
	return String();
}

Calculator::Calculator()
{
	postfix = String();
}

Calculator::~Calculator()
{
}

int Calculator::setExpression(const char* expr)
{
	char* expression = strdup(expr);
	char* ptr = strtok(expression, " ");
	int list = 0;
	while (ptr != NULL)              
	{
		String s(ptr, strlen(ptr));
		tokens.addItem(s);
		list++;
		ptr = strtok(NULL, " ");      
	}
	//postfix;
	makePostFix();
	evaluation();
	return 0;
}

String Calculator::getPostFix()
{
	return postfix;
}

int Calculator::getValue()
{
	return value;
}
