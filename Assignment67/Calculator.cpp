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
	delete[] &tokens;
	tokens = token;
	return postf;
}

int Calculator::evaluation()
{
	//�����ڸ� ���������� ����
	//�����ڸ� ����ġ��,
	//������ ��ġ�� n�̶� �ϰ�
	//n-1, n-2�� �׻� �����ϸ�, �ǿ�������.
	//n-1�� n-2�� �ش� op�� ����ϰ� ���� ���ÿ� ����
	//�����ڿ� n-1, n-2���� �����ϰ� ���� ����� ��� �����Ѵ�.
	//
	for (int i = 0; i < tokens.length; i++)
	{
		if (!tokens.getItem(i).isDigit())
		{
			//���ڰ� �ƴ�
			//�ش� �������� n-2�� �������� ����Ѵ��� n-2����ġ�� ������� ����ִ´�.
			int operand1 = tokens.getItem(i - 2).toInt32();
			int operand2 = tokens.getItem(i - 1).toInt32();
			char op = getOpCharacter(tokens.getItem(i));
			tokens.removeAt(i - 2);
			tokens.removeAt(i - 2);
			tokens.removeAt(i - 2);
			//�����ϰ� �����ε����� �Ѿ
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
			String resultString((char *)"",1);
			//integer to String
			char buff[256];
			sprintf(buff, "%d", result);
			resultString.Concat(String(buff, strlen(buff)));
			tokens.insertItem(i-2, resultString);
		}
	}
	//������ ������ ���� ��ū�� �� �ϳ��� ���ƾ� ��.
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

	if (s == plus) return '+';
	if (s == minus) return '-';
	if (s == multiply) return '*';
	if (s == divide) return '/';
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
	delete[] &tokens;
	delete[] &postfix;
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
	postfix = makePostFix();
	evaluation();
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
