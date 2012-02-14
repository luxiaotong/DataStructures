#ifndef LUXIAOTONG_H
#define LUXIAOTONG_H
#include <iostream>
using namespace std;

typedef int IntType;
typedef char CharType;
typedef char * StringType;

class Luxiaotong
{
    public:
        IntType Precede(IntType tmp1, IntType tmp2); //表达式求值用到的判断优先级
        void Display(StringType prompt);
    protected:
    private:
};

#endif // LUXIAOTONG_H
