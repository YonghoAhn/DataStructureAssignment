#include "Calculator.h"
#include <string.h>
#include "Stack.h"

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
	for (int idx = 0; idx < tokens.length; idx++) {
		String s = tokens.getItem(idx);

		if (s.isDigit())
		{
			token.addItem(s);
		}
		else
		{
			//문자임 -> 기호 6개( (, ), +,-,/,* )중 무엇인지 식별
			// 어떤 기호인지에 따라 분류해서 행동을 변경
			// IF문 써야할듯?
			//
			if (s == leftBracket)
			{
				//stack push left bracket
				//무조건 스택에 삽입
				stackOperator.Push(s);
			}
			else if (s == rightBracket)
			{
				//왼쪽 괄호를 만날때까지 빼내서
				//리스트에 추가
				while (!stackOperator.IsEmpty())
				{
					String op = stackOperator.Top;
					stackOperator.Pop();
					char ch = getOpCharacter(op);
					if (ch != '(') token.addItem(op);
					else break;
				}

			}
			else if (s == plus || s == minus || s == divide || s == multiply)
			{
				//현재 연산자보다 우선순위가 높은 연산자들을 stack에서 빼냄
				//그다음 현재 연산자를 스택에 삽입.
				//stack top이 나보다 연산순위가 높다면? 빼내서 결과물 리스트에 추가하고, 아니라면 넣는다.
				while ((!stackOperator.IsEmpty()) && getOpPriority(getOpCharacter(stackOperator.Top), getOpCharacter(s)))
				{
					token.addItem(stackOperator.Top);
					stackOperator.Pop();
				}
				stackOperator.Push(s);
			}

		}
	}
	//모든 반복이 끝나고 남은 연산자들을 후위식에 concat
	while (!stackOperator.IsEmpty())
	{
		token.addItem(stackOperator.Top);
		stackOperator.Pop();
	}
	//완성된 토큰리스트를 String으로 만들기
	for (int i = 0; i < token.length; i++)
	{
		postf.Concat(token.getItem(i));
	}
	return postf;
}

int Calculator::evaluation()
{
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

	if (s == plus) return '+';
	if (s == minus) return '-';
	if (s == multiply) return '*';
	if (s == divide) return '/';
	return 0;
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
	// expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수
	// Split expression by space(' '), and expression is always safe.
	//strtok 써야함
	char* expression = strdup(expr);
	char* ptr = strtok(expression, " ");
	int list = 0;
	while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
	{
		String s(ptr, strlen(ptr));
		tokens.addItem(s);
		list++;
		ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환
	}
	String expr = makePostFix();

	delete[] expression;
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
