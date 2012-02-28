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
        void ReplaceByPos(StringType &s, int start, int end, StringType v);     //被Replace调用
        void Replace(StringType &s, StringType t, StringType v);    //将串s中与t相等的部分替换成v
        void getNext(StringType s, IntType (&next) [MAXSIZE]);      //被KMP调用，返回next数组
        bool KMP(StringType s, StringType t);       //著名的KMP算法
        void KindOfChar(StringType s);      //求串s所含的不同字符的总数，和每种字符的个数
        void DelByPos(StringType &s, int start, int end);       //跟据给定位置删除子串
        void DelString(StringType &s, StringType t);     //删除s中所有与t相等的子串
};

#endif // CUSTOMSTRING_H
