#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H
typedef char * StringType;
typedef int IntType;
#define MAXSIZE 10000
#include <iostream>
#include <cstring>
#include <Luxiaotong.h>
using namespace std;

class CustomString
{
    public:
        void StrAssign(StringType &t, StringType s);
        int StrCompare(StringType s, StringType t);
        int StrLength(StringType s);
        StringType Concat(StringType s, StringType t);
        StringType SubString(StringType s, int start, int len);
        StringType Reverse(StringType s);
        void ReplaceByPos(StringType &s, int start, int end, StringType v);     //��Replace����
        void Replace(StringType &s, StringType t, StringType v);    //����s����t��ȵĲ����滻��v
        void getNext(StringType s, IntType (&next) [MAXSIZE]);      //��KMP���ã�����next����
        bool KMP(StringType s, StringType t);       //������KMP�㷨
        void KindOfChar(StringType s);      //��s�����Ĳ�ͬ�ַ�����������ÿ���ַ��ĸ���
        void DelByPos(StringType &s, int start, int end);       //���ݸ���λ��ɾ���Ӵ�
        void DelString(StringType &s, StringType t);     //ɾ��s��������t��ȵ��Ӵ�
};

#endif // CUSTOMSTRING_H
