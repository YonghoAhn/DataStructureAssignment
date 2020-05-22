#pragma once
#include "String.h"
#include "List.h"

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

    String itos(int value);
public:
    Calculator();
    ~Calculator();

    int setExpression(const char* expr);            // expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�      
                                                    // ������ ���� ��� 0�� ����

    String getPostFix();                            // ��ȯ�� ����ǥ����� ��ȯ

    int getValue();                                 // ���� �������� --> ����� ����
};