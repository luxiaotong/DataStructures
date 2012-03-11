#include<iostream>
#include "Stack.h"
using namespace std;

bool Stack :: Push(Stack &s, StackType x)
{
    if(s . top - s . base >= s . stacksize)
    {
        s . base = new StackType[STACK_INIT_SIZE + STACKINCREAMENT];
        s . top = s . base + s . stacksize;
        s . stacksize += STACKINCREAMENT;
    }
    *s . top = x;
    s . top = s . top + 1;
    return true;
}
bool Stack :: Pop(Stack &s, StackType &x)
{
    if(s . top == s . base) return -1;
    x = *(s . top - 1);
    s . top = s . top - 1;
    return true;
}
StackType Stack :: GetTop(Stack s)
{
    StackType x;
    x = *(s . top - 1);
    return x;
}
int Stack :: StackLength(Stack s)
{
    return s . top - s . base;
}
void Stack :: InitStack(Stack &s)
{
    s . base = new StackType[STACK_INIT_SIZE];
    //if(!s.base) exit(OVERFLOW);
    s . top = s . base;
    s . stacksize = STACK_INIT_SIZE;
    return;
}
bool Stack :: StackEmpty(Stack s)
{
    if(s . top == s . base)
        return true;
    else
        return false;
}
bool Stack :: ClearStack(Stack &s)
{
    StackType x;
    while(!s . StackEmpty(s))
    {
        s . Pop(s, x);
    }
    return true;
}
bool Stack :: StackTraverse(Stack s)
{
    StackType *tmp = s . base;
    while(tmp != s . top)
    {
        cout << *tmp << " ";
        tmp = tmp + 1;
    }
    cout << endl;
    return true;
}
