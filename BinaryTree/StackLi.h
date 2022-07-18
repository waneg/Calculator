#ifndef _STACKLI_H
#define _STACKLI_H

#include <iostream>
#include <exception>

template <class T>
class LinkedStack {
public:
    LinkedStack();
    ~LinkedStack();

    bool IsEmpty() const;
    bool IsFull() const;
    const T& Top() const;
    void Pop();
    void MakeEmpty();
    void Push(const T& x);
    const T& TopAndPop();

private:
    struct ListNode
    {
        T element;
        ListNode* next;

        ListNode(const T& theElement, ListNode* n = NULL)
            : element(theElement), next(n) {}
    };

    ListNode* top;
};
#endif

// 构造函数
template<class T>
LinkedStack<T> ::LinkedStack() {}

// 析构函数
template<class T>
LinkedStack<T> :: ~LinkedStack()
{
    ListNode* next;
    while (top)
    {
        next = top->next;
        delete top;
        top = next;
    }
}

//栈是否空
template<class T>
bool LinkedStack<T>::IsEmpty() const
{
    return top == nullptr;
}

//栈是否满
template<class T>
bool LinkedStack<T>::IsFull() const
{
    try {
        ListNode* p = new ListNode;
        delete p;
        return false;
    }
    catch (int) {
        return true;
    }
}

//返回栈顶元素
template<class T>
const T& LinkedStack<T>::Top() const
{
    if (IsEmpty())
        throw "IsEmpty";
    return top->element;
}

//出栈
template<class T>
void LinkedStack<T>::Pop()
{
    if (IsEmpty())
        throw "IsEmpty";
    ListNode* p = top;
    top = top->next;
    delete p;
}

//添加元素x
template<class T>
void LinkedStack<T>::Push(const T& x)
{
    ListNode* p = new ListNode(x, top);
    top = p;
    return;
}

//清空栈
template<class T>
void LinkedStack<T>::MakeEmpty()
{
    ListNode* next;
    while (top)
    {
        next = top->next;
        delete top;
        top = next;
    }
}

template<class T>
const T& LinkedStack<T>::TopAndPop() {
    if (IsEmpty())
        throw "StackIsEmpty";
    else
    {
        T tmp = Top();
        Pop();
        return tmp;
    }
}
