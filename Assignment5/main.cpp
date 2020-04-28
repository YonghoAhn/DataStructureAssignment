#include <iostream>
#include "Stack.h"
#include "Queue.h"
int main(int argc, char* argv[])
{
    Stack<int> s;
    cout << "init" << endl;
    s.Print();
    cout << "Push 1" << endl;
    s.Push(1);
    s.Print();
    cout << "Push 2" << endl;
    s.Push(2);
    s.Print();
    cout << "Pop" << endl;
    s.Pop();
    s.Print();
    cout << "Push 3" << endl;
    s.Push(3);
    s.Print();
    cout << "Pop 2 times" << endl;
    s.Pop();
    s.Pop();
    cout << "Final" << endl;
    s.Print();
    cout << "==============Queue==============" << endl;
    Queue<int> q(2);
    q.Print();
    cout << "Push 1" << endl;
    q.Push(1);
    q.Print();
    cout << "Push 2" << endl;
    q.Push(2);
    q.Print();
    cout << "Pop" << endl;
    q.Pop();
    q.Print();
    cout << "Push 3" << endl;
    q.Push(3);
    q.Print();
    cout << "Pop" << endl;
    q.Pop();
    q.Pop();
    q.Print();
    return 0;
}
