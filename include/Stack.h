#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
#include "Global.h"
//typedef int CharType;
//typedef char CharType;

class Stack
{
    public:
        void InitStack(Stack &s);
        bool Push(Stack &s, StackType x);
        bool Pop(Stack &s, StackType &x);
        StackType GetTop(Stack s);
        int StackLength(Stack s);
        bool StackEmpty(Stack s);
        bool ClearStack(Stack &s);
        bool StackTraverse(Stack s);
    private:
        StackType *base;
        StackType *top;
        int stacksize;
};

#endif // STACK_H
