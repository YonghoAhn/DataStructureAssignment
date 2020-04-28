#pragma once
template <class T>
class Queue
{
public:
    Queue(int queueCapacity = 10); 
    void Push(const T& item);

    bool IsEmpty();

    void Pop();

    T& Rear();
    T& Front();

    void Print();
private:
    int front;
    int rear;
    T* queue;
    int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
    queue = new T[capacity];
    front = rear = 0;
}

template <class T>
bool  Queue<T>::IsEmpty()
{
    if (front == rear) return true;
    else return false;
}

template <class T>
void Queue<T>::Push(const T& x)
{
    int k = (rear + 1) % capacity;
    if (front == k) {
        T* newQueue = new T[2 * capacity];
        int start = (front + 1) % capacity;
        if (start < 2)
            copy(queue + start, queue + start + capacity - 1, newQueue);
        else
        {
            copy(queue + start, queue + capacity, newQueue);
            copy(queue, queue + rear + 1, newQueue + capacity - start);
        }
        front = 2 * capacity - 1;
        rear = capacity - 2;
        capacity *= 2;
        delete[] queue;
        queue = newQueue;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = x;
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty()) throw "Queue is empty";
    front = (front + 1) % capacity;
    queue[front].~T();
}

template<class T>
inline T& Queue<T>::Front()
{
    if (IsEmpty()) throw "Queue is empty";
    return queue[(front + 1) % capacity];
}

template<class T>
inline T& Queue<T>::Rear()
{
    if (IsEmpty()) throw "Queue is empty";
    return queue[rear];
}

template <class T>
void Queue<T>::Print()
{
    cout << "front = " << front << " rear = " << rear << endl;
    for (int i = 0; i < capacity; i++)
        cout << "  " << i << " : " << queue[i] << endl;
    cout << endl;
}