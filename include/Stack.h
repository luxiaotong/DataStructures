#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10
typedef int IntType;
typedef char CharType;
class SqStack
{
    private:
        IntType *base;
        IntType *top;
        int stacksize;
        friend class Stack;
};
class Stack
{
    public:
        void InitStack(SqStack &s);                     //对栈进行初始化
        bool Push(SqStack &s, IntType x);      //入栈
        bool Pop(SqStack &s, IntType &x);      //出栈
        IntType GetTop(SqStack s);         //获取栈顶元素
        int StackLength(SqStack s);             //获取栈的长度
        bool StackEmpty(SqStack s);         //判断是否为空
        bool ClearStack(SqStack &s);        //清空栈
        bool StackTraverse(SqStack s);      //遍历栈
        int g_3_24(int m, int n);
        int F_3_25(int n);
        int F_3_25_2(int n);
        int sqrt_3_26(int n, int p, int e);
        int akm_3_27(int m, int n);
};

#endif // STACK_H
