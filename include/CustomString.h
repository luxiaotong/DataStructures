#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H
typedef char * StringType;
typedef int IntType;
#include <iostream>
#include <cstring>
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
        void Replace(StringType &s, StringType t, StringType v);
        void getNext(StringType s, IntType (&next) [10]);
        bool KMP(StringType s, StringType t);
};

#endif // CUSTOMSTRING_H
