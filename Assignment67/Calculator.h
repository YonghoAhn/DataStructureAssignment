#pragma once
#include "String.h"
#include "List.h"

/*
�� List<String> �� expression �� postfix �� �����ϱ� expession ���޵� ���ڿ��� ��ū����Ʈ�� �����ϴ� �� ���

    ��, ��ȣ, ������, �ǿ����ڸ� �����ؼ� �ϳ��� ������ ����

    (��ū : ���� �Ǵ� �ǹ��ִ� ������ �߷��� ���ڿ� )

   ��) (3+5)/10 �� ����Ʈ�� ���� :  ( -> 3 -> + -> 5 -> ) -> / -> 10

�� Postfix �� �����Ҷ� List<String> �� ����� ��ū���� ������, ���ǳ��뿡�� ������ �˰����� �����Ͽ� ����

1. Caculator �� �������� ��Ģ���� (���ϱ�, ����, ���ϱ�, ������) �� ��ȣ() �� �����Ͻø� �˴ϴ�.

2. strtok �� ���� ������ ���̺귯�� �Լ��� ����ϼŵ� �˴ϴ�.

�Է��� �׻� ������ ���� ���ĸ� ������, �����ڿ� �ǿ����� ���̿��� "����" �� �����Ѵ�.

�Է¿�) 3 + 55 + 10 * ( 4 + 24 )

       1233 / 55 + 111
*/

class Calculator
{
private:
    List<String> tokens;

    int value;                                      // ���� ��

    String postfix;                                 // ����ǥ��� = ���� �������� �ʱ�ȭ

    String makePostFix();                           // postfix �� �����ϴ� �Լ�

    int evaluation();                               // postfix �� ����ϴ� �Լ�

    int getOpPriority(const char op);

    bool getOpPriority(const char op1, const char op2);

    char getOpCharacter(String s);
public:
    Calculator();
    ~Calculator();

    int setExpression(const char* expr);            // expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�      
                                                    // ������ ���� ��� 0�� ����

	String getPostFix();                            // ��ȯ�� ����ǥ����� ��ȯ

    int getValue();                                 // ���� �������� --> ����� ����
};

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               