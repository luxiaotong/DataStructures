#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
//typedef int CharType;
typedef char CharType;

class Stack
{
    public:
        void InitStack(Stack &s);
        bool Push(Stack &s, CharType x);
        bool Pop(Stack &s, CharType &x);
        CharType GetTop(Stack s);
        int StackLength(Stack s);
        bool StackEmpty(Stack s);
        bool ClearStack(Stack &s);
        bool StackTraverse(Stack s);
    private:
        CharType *base;
        CharType *top;
        int stacksize;
};

#endif // STACK_H
