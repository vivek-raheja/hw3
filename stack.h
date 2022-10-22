#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
struct MyNode
{
    T data;
    MyNode<T>* prev;
};

template <typename T>
class Stack
{
public:
    Stack();
    virtual size_t size() const;
	virtual bool empty() const;
    virtual void push(const T& item);
    virtual T& pop();
    virtual T& top();
    
private:
    unsigned totStackSize;
    MyNode<T>* currentTop;
    T returnT;
};

template<typename T>
inline Stack<T>::Stack() :
    totStackSize(0),
    currentTop(NULL) {}

template<typename T>
inline void Stack<T>::push(const T& item)
{
    if (totStackSize == 0)
    {
        currentTop = new MyNode<T>;
        currentTop->data = item;
        totStackSize++;
    }
    else
    {
        MyNode<T>* tempNode = new MyNode<T>;
        tempNode->data = item;
        tempNode->prev = currentTop;
        currentTop = tempNode;
        totStackSize++;
    }
}

template<typename T>
inline T & Stack<T>::pop()
{
    if (totStackSize > 1)
    {
        returnT = currentTop->data;
        MyNode<T>* tempT = currentTop;
        currentTop = currentTop->prev;
        delete tempT;
        totStackSize--;
        return returnT;
    }
    else if (totStackSize > 0)
    {
        returnT = currentTop->data;
        MyNode<T>* tempT = currentTop;
        currentTop = NULL;
        delete tempT;
        totStackSize--;
        return returnT;
    }
    else
    {
         throw std::underflow_error("No more elements found");
    }
}

template<typename T>
inline T & Stack<T>::top()
{
    if (totStackSize > 0)
    {
        return currentTop->data;
    }
    else
    {
         throw std::underflow_error("No more elements found");
    }
}

template<typename T>
inline size_t Stack<T>::size() const
{
    return totStackSize;
}

template<typename T>
inline bool Stack<T>::empty() const
{
    return totStackSize < 1;
}

#endif