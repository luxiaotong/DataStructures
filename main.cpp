#include <iostream>
#include <string.h>
#include "Sequence.h"
#include "LinkList.h"
#include "Stack.h"
#include "CustomString.h"
#include "Luxiaotong.h"
using namespace std;


int main()
{
    StringType s = new char[100];
    StringType t        = new char[100];
    CustomString cs;
    Luxiaotong l;

    l.Display("输入字符串1");
    cin.getline(s, 100);
    l.Display("输入字符串2");
    cin.getline(t, 100);
    cout << cs.StrCompare(s, t);
    /*
    //*****************KMP
    char  str[100], mod[100];
    int i, j, next[10], len1 = strlen(str), len2 = strlen(mod);
    cout << "********************输入字符串********************" << endl;
    cin >> str;
    cout << "********************输入模式串********************" << endl;
    cin >> mod;

    //求next的值
    i = -1;
    j = 0;
    next[0] = -1;
    while(j < len2)
    {
        if(i == -1 || mod[i] == mod[j])
        {
            i ++;
            j ++;
            next[j] = i;
        }
        else
        {
            i = next[i];
        }
    }
    //kmp
    i = 0;
    j = 0;
    while(i < len1 && j < len2)
    {
        if(j == -1 || str[i] == mod[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == len2)   cout << "匹配成功" << endl;
    else                cout << "匹配失败" << endl;
    cout << "字符串: " << str << endl;
    cout << "模式串: " << mod << endl;

    //*****************3_27*********递归
    Stack s;
    cout << s.akm_3_27(1, 0) << endl;

    //*****************3_26
    Stack s;
    cout << s.sqrt_3_26(9, 3, 1) << endl;

    //******************3_25*******非递归
    Stack s;
    cout << s.F_3_25_2(4) << endl;

    //******************3_25*******递归
    Stack s;
    cout << s.F_3_25(100) << endl;

    //*******************3_24
    Stack s;
    s.g_3_24(5, 2);

    //*******************3_21*********表达式求值
    Stack s;
    SqStack s1, s2;
    Luxiaotong lux;
    char data[100];
    char x;
    int i = 0;
    s.InitStack(s1);
    s.InitStack(s2);
    s.Push(s1, '#');
    cin.getline(data, 100);

    while(1)
    {
        if(data[i] == '#')
        {
            if(s.GetTop(s1) == '#')
                break;
            else
            {
                while(s.GetTop(s1) != '#')
                {
                    //cout << "gettop: " << s1.GetTop(s1) << endl;
                    s.Pop(s1, x);
                    s.Push(s2, x);

                }
                break;
            }
        }

        if(data[i] >= 'a' && data[i] <= 'z')
        {
            s.Push(s2, data[i]);
            //cout << "char: " << data[i] << endl;
        }
        else
        {
            //cout << "operator: " << data[i] << endl;

            //cout << s.GetTop(s1) << " " << data[i] << " "<< lux.Precede(s.GetTop(s1), data[i]) << endl;
            //s.Push(s1, data[i]);

            switch(lux.Precede(s.GetTop(s1), data[i]))
            {
                case '<' : s.Push(s1, data[i]); break;
                case '>' :  while(lux.Precede(s.GetTop(s1), data[i]) == '>')
                                {
                                    s.Pop(s1, x);
                                    s.Push(s2, x);
                                }
                                s.Push(s1, data[i]);
                                break;
                case '=' : s.Pop(s1, x); break;
            }
        }
        s.StackTraverse(s1);
        i++;
    }
    s.StackTraverse(s1);
    s.StackTraverse(s2);

    //*************************Josephus
    int count = 0;
    LinkList l;
    LinkNode * p = new LinkNode;
    LinkNode * tmp = new LinkNode;
    p = l.ListInit3();
    tmp = p;
    //测试循环链表
    for(int i = 0; i < 13; i++)
    {
        tmp = tmp->next;
        cout << tmp->data << " ";
    }
    cout << endl;

    while(tmp->next->data != tmp->data)
    {
        count ++;
        if(count % 3 == 0)
        {
            cout << tmp->next->data << endl;
            tmp->next = tmp->next->next;
            continue;
        }
        tmp = tmp->next;
    }
    cout << tmp->data << endl;

    //******************3_19
    Stack s;
    SqStack s1, s2;
    s.InitStack(s1);
    s.InitStack(s2);
    char x;
    char *c = new char[100];
    cin . getline(c, 100);
    for(int i = 0; i < strlen(c); i++)
    {
        if(*(c + i) == '[' || *(c + i) == ']' || *(c + i) == '(' || *(c + i) == ')' || *(c + i) == '{' || *(c + i) == '}')
            s.Push(s1, *(c + i));
    }
    while(s.StackEmpty(s1))
    {
        s.Pop(s1, x);
        if(x == '[' || x == '(' || x == '{')
            s.Push(s2, x);
        if(x == ']' || x == ')' || x == '}')
        {
            if(s.StackEmpty(s2))
                cout << "the brackets in expresion is not match";
            if(x == s1.GetTop(s2))
        }
    }

    //******************3_18
    Stack s;
    SqStack s1, s2, s3, s4, s5;
    s.InitStack(s1);
    s.InitStack(s2);
    s.InitStack(s3);
    s.InitStack(s4);
    s.InitStack(s5);
    char x;
    char *c  = new char[100];
    cin . getline(c, 100);
    for(int i = 0; i < strlen(c); i++)
    {
        //入栈
        s.Push(s1, *(c + i));
    }
    while(!s.StackEmpty(s1))
    {
        s.Pop(s1, x);
        switch(x)
        {
            case '(' : s.Push(s2, x);break;
            case ')' : s.Push(s3, x);break;
            case '[' : s.Push(s4, x);break;
            case ']' : s.Push(s5, x);break;
        }
    }
    if(!s.StackEmpty(s1))
        s.StackTraverse(s1);
    if(!s.StackEmpty(s2))
        s.StackTraverse(s2);
    if(!s.StackEmpty(s3))
        s.StackTraverse(s3);
    if(!s.StackEmpty(s4))
        s.StackTraverse(s4);
    if(!s.StackEmpty(s5))
        s.StackTraverse(s5);
    if(s.StackLength(s2) == s.StackLength(s3))
        cout << "'(' is equal to ')'" << endl;
    else
        cout << "'(' is not equal to ')'" << endl;
    if(s.StackLength(s4) == s.StackLength(s5))
        cout << "'[' is equal to ']'" << endl;
    else
        cout << "'[' is not equal to ']'" << endl;

    ///***********************3_17
    Stack s;
    SqStack s1,s2;
    s.InitStack(s1);
    s.InitStack(s2);
    char x, x1;
    //输入一串字符并入栈
    cin >> x;
    while(x != '@')
    {
        if(x != ' ')
            s.Push(s1, x);
        cin >> x;
    }
    s.StackTraverse(s1);
    //挨个出栈s并入栈s1直到遇见‘&’
    s.Pop(s1, x);
    while(x != '&')
    {
        s.Push(s2, x);
        s.Pop(s1, x);
        if(s.StackEmpty(s1) || s1.StackEmpty(s2))
        {
            cout << "no" << endl;
            return 0;
        }
    }
    //栈s和s1逐个Pop并比较
    while(1)
    {
        s.Pop(s1, x);
        s.Pop(s2, x1);
        if(x == x1)
        {
            if(s.StackEmpty(s1) && s.StackEmpty(s2))
            {
                cout << "yes" << endl;
                break;
                return 0;
            }
            else if(s.StackEmpty(s1) && !s.StackEmpty(s2) || !s.StackEmpty(s1) && s.StackEmpty(s2))
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
    Stack s;
    SqStack s1, s5, s6;
    s . InitStack(s1);
    s . InitStack(s5);
    s . InitStack(s6);
    for(int i = 0; i < 10; i++)
        s . Push(s1, arr[i]);
    while(!s.StackEmpty(s1))
    {
        s . Pop(s1, x);
        if(x == 5)
            s.Push(s5, x);
        if(x == 6)
            s.Push(s6, x);
    }
    while(!s.StackEmpty(s5))
    {
        s.Pop(s5, x);
        s.Push(s1, x);
    }
    while(!s.StackEmpty(s6))
    {
        s.Pop(s6, x);
        s.Push(s1, x);
    }
    s.StackTraverse(s1);

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
