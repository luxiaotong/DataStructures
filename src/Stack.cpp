#include<iostream>
#include "Stack.h"
#include <cmath>
using namespace std;

bool Stack :: Push(SqStack &s, IntType x)
{
    if(s . top - s . base >= s . stacksize)
    {
        s . base = new IntType[STACK_INIT_SIZE + STACKINCREAMENT];
        s . top = s . base + s . stacksize;
        s . stacksize += STACKINCREAMENT;
    }
    *s . top = x;
    s . top = s . top + 1;
    return true;
}
bool Stack :: Pop(SqStack &s, IntType &x)
{
    if(s . top == s . base) return -1;
    x = *(s . top - 1);
    s . top = s . top - 1;
    return true;
}
IntType Stack :: GetTop(SqStack s)
{
    IntType x;
    x = *(s . top - 1);
    return x;
}
int Stack :: StackLength(SqStack s)
{
    return s . top - s . base;
}
void Stack :: InitStack(SqStack &s)
{
    s . base = new IntType[STACK_INIT_SIZE];
    //if(!s.base) exit(OVERFLOW);
    s . top = s . base;
    s . stacksize = STACK_INIT_SIZE;
    return;
}
bool Stack :: StackEmpty(SqStack s)
{
    if(s . top == s . base)
        return true;
    else
        return false;
}
bool Stack :: ClearStack(SqStack &s)
{
    IntType x;
    while(!this->StackEmpty(s))
    {
        this->Pop(s, x);
    }
    return true;
}
bool Stack :: StackTraverse(SqStack s)
{
    IntType *tmp = s . base;
    while(tmp != s . top)
    {
        cout << *tmp << " ";
        tmp = tmp + 1;
    }
    cout << endl;
    return true;
}
//实现3.24题中得函数g(m, n)
int Stack :: g_3_24(int m, int n)
{
    if(m > 0 && n >= 0)
    {
        cout << "m : " << m << " " << "n : " << n << endl;
        g_3_24(m - 1, 2*n);
    }
    if(m = 0 && n >= 0)
        return 0;
}
//实现3.25题中的函数F(n)  --递归
int Stack :: F_3_25(int n)
{
    if(n == 0)
        return n + 1;
    if(n > 0)
    {
        return n*F_3_25(n/2);
    }
}
//实现3.25题中的函数F(n) --非递归
int Stack :: F_3_25_2(int n)
{
    int tmp;
    int rst = 1;
    SqStack s1;
    InitStack(s1);
    while(1)
    {
        if(n == 0)
        {
            //Push(s1, n + 1);
            while(!StackEmpty(s1))
            {
                Pop(s1, tmp);
                rst = rst * tmp;
            }
            break;
        }
        else
        {
            Push(s1, n);
        }
        n = n / 2;
    }
    return rst;
}
//3.26题中的求平方根
int Stack :: sqrt_3_26(int n, int p, int e)
{
    if(fabs(p * p - n) < e)
        return p;
    else
        sqrt_3_26(n, 1 / 2 * (p + n / p), e);
}
//3.27题中的akm函数递归实现
int Stack :: akm_3_27(int m, int n)
{
    if(m == 0)
        return n + 1;
    else if (n == 0)
        akm_3_27(m - 1, 1);
    else
        akm_3_27(m - 1, akm_3_27(m, n - 1));
}

