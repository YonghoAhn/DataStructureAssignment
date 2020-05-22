#pragma once
#include <iostream>
using namespace std;
template <class T>
class Stack
{
public:
    Stack(int MaxStackSize = 10);

    void Push(const T& item);

    bool IsEmpty();

    void Pop();

    T* Top();
    void Print();
private:
    int top;
    T* stack;
    int MaxSize;
};

template <class T>
Stack<T>::Stack(int MaxStackSize) : MaxSize(MaxStackSize)
{
    stack = new T[MaxSize];
    top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty()
{
    if (top == -1) return true;
    else return false;
}

template <class T>
void Stack<T>::Push(const T& x)
{
    if (top == MaxSize - 1)
    {
        T* temp = new T[MaxSize * 2];
        copy(stack, stack + MaxSize, temp);
        delete[] stack;
        stack = temp;
        MaxSize *= 2;
    }
    stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty()) throw "Stack is empty";
    stack[top--].~T();
}

template <class T>
T* Stack<T>::Top()
{
    if (IsEmpty()) throw "Stack is empty";
    return &stack[top];
}

template <class T>
void Stack<T>::Print()
{
    cout << "top = " << top << endl;
    for (int i = 0; i <= top; i++)
        cout << i << ":" << stack[i] << endl;
}
