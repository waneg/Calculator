#ifndef _STACKAR_H
#define _STACKAR_H
#include <iostream>

template <class Object>
class SqStack {
public:
    explicit SqStack(int capacity = 10);
    bool IsEmpty() const;
    bool IsFull() const;
    const Object& Top() const;

    void MakeEmpty()
    {
        top = -1;
    };
    void Pop();
    void Push(const Object& x);
    Object TopAndPop();

private:
    int MaxSize;
    int top;
    Object* theArray;
};
#endif

//栈的构造
template <class Object>
SqStack<Object>::SqStack(int capacity)
{
    MaxSize = capacity;
    top = -1;
    theArray = new Object[MaxSize];
}

//栈判空
template <class Object>
bool SqStack<Object>::IsEmpty() const
{
    return top == -1;
}

//栈判满
template <class Object>
bool SqStack<Object>::IsFull() const
{
    return top == MaxSize - 1;
}

//入栈，当前栈非满时插入x到栈顶，否则抛出异常Overflow
template <class Object>
void SqStack <Object>::Push(const Object& x)
{
    if (IsFull())
        throw "OverFlow";
    theArray[++top] = x;
}

//出栈，当栈非空是删除栈顶，否则抛出异常Underflow
template <class Object>
void SqStack<Object>::Pop()
{
    if (IsEmpty())
        throw "Underflow";
    top--;
}

template <class Object>
Object SqStack<Object>::TopAndPop()
{
    if (IsEmpty())
        throw "Underflow";
    return theArray[top--];
}

template <class Object>
const Object& SqStack<Object>::Top() const
{
    if (IsEmpty())
        throw "Underflow";
    return theArray[top];
}
