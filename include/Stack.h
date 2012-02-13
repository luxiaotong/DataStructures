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
        void InitStack(SqStack &s);                     //��ջ���г�ʼ��
        bool Push(SqStack &s, IntType x);      //��ջ
        bool Pop(SqStack &s, IntType &x);      //��ջ
        IntType GetTop(SqStack s);         //��ȡջ��Ԫ��
        int StackLength(SqStack s);             //��ȡջ�ĳ���
        bool StackEmpty(SqStack s);         //�ж��Ƿ�Ϊ��
        bool ClearStack(SqStack &s);        //���ջ
        bool StackTraverse(SqStack s);      //����ջ
        int g_3_24(int m, int n);
        int F_3_25(int n);
        int F_3_25_2(int n);
        int sqrt_3_26(int n, int p, int e);
        int akm_3_27(int m, int n);
};

#endif // STACK_H
