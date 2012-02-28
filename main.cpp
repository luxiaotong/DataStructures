#include <iostream>
#include <cstring>
#include "Stack.h"
#include "Luxiaotong.h"
#include "CustomString.h"
//typedef char * StringType;
//typedef int IntType;
//#define MAXSIZE 100
using namespace std;

int main()
{
    StringType s = new char[MAXSIZE];
    StringType t = new char[MAXSIZE];
    Luxiaotong l;
    CustomString cs;
    l.Display("输入字符串s:");
    cin.getline(s, MAXSIZE);
    l.Display("输入字符串t:");
    cin.getline(t, MAXSIZE);
    cs.DelString(s, t);
    l.Display(s);
    /*
    StringType s = new char[MAXSIZE];
    Luxiaotong l;
    CustomString cs;
    l.Display("输入字符串s:");
    cin.getline(s, MAXSIZE, '^');
    cs.KindOfChar(s);

    StringType s = new char[MAXSIZE];
    StringType t = new char[MAXSIZE];
    StringType v = new char[MAXSIZE];
    Luxiaotong l;
    CustomString cs;
    l.Display("输入字符串s:");
    cin.getline(s, MAXSIZE);
    l.Display("输入字符串t:");
    cin.getline(t, MAXSIZE);
    l.Display("输入字符串v:");
    cin.getline(v, MAXSIZE);
    cs.Replace(s, t, v);
    l.Display(s);

    StringType t = new char[10];
    CustomString cs;
    cin.getline(t, 10);
    cout << cs.Reverse(t) << endl;

    StringType t = new char[10];
    CustomString cs;
    cin.getline(t, 10);
    cout << cs.SubString(t, 2, 5) << endl;

    StringType t = new char[10];
    StringType s = new char[10];
    CustomString cs;
    cin.getline(s, 10);
    cin.getline(t, 10);
    cout << cs.Concat(s, t) << endl;

    StringType t = new char[10];
    CustomString cs;
    cin.getline(t, 10);
    cout << cs.StrLength(t) << endl;
    cout << strlen(t) << endl;

    StringType t = new char[10];
    StringType s = new char[10];
    CustomString cs;
    cin.getline(s, 10);
    cin.getline(t, 10);
    cout << cs.StrCompare(s, t) << endl;

    StringType t = new char[2];
    StringType s = new char[10];
    CustomString cs;
    cin.getline(s, 10);
    cs.StrAssign(t, s);
    cout << t << " " << strlen(t) << endl;

    //******************3_19
    Stack s, s1, s2;
    s.InitStack(s);
    s1.InitStack(s1);
    char x;
    char *c  = new char[100];
    cin . getline(c, 100);
    for(int i = 0; i < strlen(c); i++)
    {
        if(*(c + i) == '[' || *(c + i) == ']' || *(c + i) == '(' || *(c + i) == ')' || *(c + i) == '{' || *(c + i) == '}')
            s.Push(s, *(c + i));
    }
    while(s.StackEmpty(s))
    {
        s.Pop(s, x);
        if(x == '[' || x == '(' || x == '{')
            s1.Push(s1, x);
        if(x == ']' || x == ')' || x == '}')
        {
            if(s1.StackEmpty(s1))
                cout << "the brackets in expresion is not match";
            if(x == s1.GetTop(s1))
        }
    }
    //******************3_18
    Stack s1, s2, s3, s4, s5;
    s1.InitStack(s1);
    s2.InitStack(s2);
    s2.InitStack(s3);
    s2.InitStack(s4);
    s2.InitStack(s5);
    char x;
    char *c  = new char[100];
    cin . getline(c, 100);
    for(int i = 0; i < strlen(c); i++)
    {
        //��ջ
        s1.Push(s1, *(c + i));
    }
    while(!s1.StackEmpty(s1))
    {
        s1.Pop(s1, x);
        switch(x)
        {
            case '(' : s2.Push(s2, x);break;
            case ')' : s3.Push(s3, x);break;
            case '[' : s4.Push(s4, x);break;
            case ']' : s5.Push(s5, x);break;
        }
    }
    if(!s1.StackEmpty(s1))
        s1.StackTraverse(s1);
    if(!s2.StackEmpty(s2))
        s2.StackTraverse(s2);
    if(!s3.StackEmpty(s3))
        s3.StackTraverse(s3);
    if(!s4.StackEmpty(s4))
        s4.StackTraverse(s4);
    if(!s5.StackEmpty(s5))
        s5.StackTraverse(s5);
    if(s2.StackLength(s2) == s3.StackLength(s3))
        cout << "'(' is equal to ')'" << endl;
    else
        cout << "'(' is not equal to ')'" << endl;
    if(s4.StackLength(s4) == s5.StackLength(s5))
        cout << "'[' is equal to ']'" << endl;
    else
        cout << "'[' is not equal to ']'" << endl;

    ///***********************3_17
    Stack s,s1;
    s.InitStack(s);
    s1.InitStack(s1);
    char x, x1;
    //����һ���ַ���ջ
    cin >> x;
    while(x != '@')
    {
        if(x != ' ')
            s.Push(s, x);
        cin >> x;
    }
    s.StackTraverse(s);
    //�����ջs����ջs1ֱ�����&��
    s.Pop(s, x);
    while(x != '&')
    {
        s1.Push(s1, x);
        s.Pop(s, x);
        if(s.StackEmpty(s) || s1.StackEmpty(s1))
        {
            cout << "no" << endl;
            return 0;
        }
    }
    //ջs��s1���Pop���Ƚ�
    while(1)
    {
        s.Pop(s, x);
        s1.Pop(s1, x1);
        if(x == x1)
        {
            if(s.StackEmpty(s) && s1.StackEmpty(s1))
            {
                cout << "yes" << endl;
                break;
                return 0;
            }
            else if(s.StackEmpty(s) && !s1.StackEmpty(s1) || !s.StackEmpty(s) && s1.StackEmpty(s1))
            {
                cout << "no" << endl;
                break;
                return 0;
            }
            else
                continue;
        }
        else
        {
            cout << "no" << endl;
            break;
            return 0;
        }
    }

    ////////////////////////3_16
    int x;
    int arr[10] = {5,5,6,6,5,6,5,6,6,5};
    Stack s, s5, s6;
    s . InitStack(s);
    s5 . InitStack(s5);
    s6 . InitStack(s6);
    for(int i = 0; i < 10; i++)
        s . Push(s, arr[i]);
    while(!s.StackEmpty(s))
    {
        s . Pop(s, x);
        if(x == 5)
            s5.Push(s5, x);
        if(x == 6)
            s6.Push(s6, x);
    }
    while(!s.StackEmpty(s5))
    {
        s5.Pop(s5, x);
        s.Push(s, x);
    }
    while(!s.StackEmpty(s6))
    {
        s6.Pop(s6, x);
        s.Push(s, x);
    }
    s.StackTraverse(s);

    //******************2_30
    LinkList l;
    IntType data;
    LinkNode * pa = new LinkNode;
    LinkNode * pb = new LinkNode;
    LinkNode * pc = new LinkNode;
    pa = l.ListInit();
    l.Display(pa);
    pb = l.ListInit2();
    l.Display(pb);
    pc = l.ListInit2();
    l.Display(pc);
    pa = l.Duplication_29(pa, pb, pc);
    l.Display(pa);


    //******************2_26
    LinkList l;
    IntType data;
    LinkNode *pa = new LinkNode;
    LinkNode *pb = new LinkNode;
    LinkNode *pc = new LinkNode;
    pa = l.ListInit2();
    l.Display(pa);
    pb = l.ListInit2();
    l.Display(pb);
    pc = l.Intersect(pa, pb);
    l.Display(pc);

    //******************2_23
    IntType data;
    LinkList l;
    LinkNode *pa = new LinkNode;
    LinkNode *pb = new LinkNode;
    LinkNode *pc = new LinkNode;

    pa->next = NULL;
    pb->next = NULL;
    cout << "insert the data to pa:" << endl;
    while(1)
    {
    cin >> data;
    if(data == -1) break;
    pa = l.Insert(pa, data);
    }
    cout << "insert the data to pb:" << endl;
    while(1)
    {
    cin >>data;
    if(data == -1) break;
    pb = l.Insert(pb, data);
    }

    pa = l.ListInit();
    pb = l.ListInit();
    l.Display(pa);
    l.Display(pb);
    pc = l.Join_24(pa, pb);
    l.Display(pc);

    */
    return 0;
}
