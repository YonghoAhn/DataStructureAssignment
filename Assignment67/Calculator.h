#pragma once
#include "String.h"
#include "List.h"

/*
※ List<String> 은 expression 을 postfix 로 변경하기 expession 전달된 문자열을 토큰리스트로 변경하는 데 사용

    즉, 괄호, 연산자, 피연산자를 구분해서 하나의 단위로 저장

    (토큰 : 공백 또는 의미있는 단위로 잘려진 문자열 )

   예) (3+5)/10 을 리스트로 변경 :  ( -> 3 -> + -> 5 -> ) -> / -> 10

※ Postfix 로 변경할때 List<String> 에 저장된 토큰들을 가지고, 강의내용에서 설명한 알고리즘을 적용하여 변경

1. Caculator 의 계산과정은 사칙연산 (더하기, 빼기, 곱하기, 나누기) 과 괄호() 만 구현하시면 됩니다.

2. strtok 와 같은 별도의 라이브러리 함수를 사용하셔도 됩니다.

입력은 항상 오류가 없는 수식만 들어오며, 연산자와 피연산자 사이에는 "공백" 이 존재한다.

입력예) 3 + 55 + 10 * ( 4 + 24 )

       1233 / 55 + 111
*/

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
public:
    Calculator();
    ~Calculator();

    int setExpression(const char* expr);            // expr에 전달된 수식(중위표기식)을 postfix로 변경하고 계산하는 함수      
                                                    // 오류가 없을 경우 0을 리턴

	String getPostFix();                            // 변환된 후위표기식을 반환

    int getValue();                                 // 수식 오류없음 --> 결과값 리턴
};

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               