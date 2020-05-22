#pragma once
#include "String.h"
#include "List.h"

class Calculator
{
private:
    List<String> tokens;

    int value;                                      // 계산된 값

    String postfix;                                 // 후위표기식 = 최초 공백으로 초기화

    String makePostFix();                           // postfix 로 변경하는 함수

    int evaluation();                               // postfix 를 계산하는 함수

    int getOpPriority(const char op);

    bool getOpPriority(const char op1, const char op2);

    char getOpCharacter(String s);

    String itos(int value);
public:
    Calculator();
    ~Calculator();

    int setExpression(const char* expr);            // expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수      
                                                    // 오류가 없을 경우 0을 리턴

    String getPostFix();                            // 변환된 후위표기식을 반환

    int getValue();                                 // 수식 오류없음 --> 결과값 리턴
};