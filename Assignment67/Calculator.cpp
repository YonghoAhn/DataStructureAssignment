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
			//������ -> ��ȣ 6��( (, ), +,-,/,* )�� �������� �ĺ�
			// � ��ȣ������ ���� �з��ؼ� �ൿ�� ����
			// IF�� ����ҵ�?
			//
			if (s == leftBracket)
			{
				//stack push left bracket
				//������ ���ÿ� ����
				stackOperator.Push(s);
			}
			else if (s == rightBracket)
			{
				//���� ��ȣ�� ���������� ������
				//����Ʈ�� �߰�
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
				//���� �����ں��� �켱������ ���� �����ڵ��� stack���� ����
				//�״��� ���� �����ڸ� ���ÿ� ����.
				//stack top�� ������ ��������� ���ٸ�? ������ ����� ����Ʈ�� �߰��ϰ�, �ƴ϶�� �ִ´�.
				while ((!stackOperator.IsEmpty()) && getOpPriority(getOpCharacter(stackOperator.Top), getOpCharacter(s)))
				{
					token.addItem(stackOperator.Top);
					stackOperator.Pop();
				}
				stackOperator.Push(s);
			}

		}
	}
	//��� �ݺ��� ������ ���� �����ڵ��� �����Ŀ� concat
	while (!stackOperator.IsEmpty())
	{
		token.addItem(stackOperator.Top);
		stackOperator.Pop();
	}
	//�ϼ��� ��ū����Ʈ�� String���� �����
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
	// expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�
	// Split expression by space(' '), and expression is always safe.
	//strtok �����
	char* expression = strdup(expr);
	char* ptr = strtok(expression, " ");
	int list = 0;
	while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
	{
		String s(ptr, strlen(ptr));
		tokens.addItem(s);
		list++;
		ptr = strtok(NULL, " ");      // ���� ���ڿ��� �߶� �����͸� ��ȯ
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
