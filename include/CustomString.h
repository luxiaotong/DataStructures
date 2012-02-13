#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <iostream>
#include <cstring>
typedef char * StringType;

using namespace std;

class CustomString
{
    public:
        void Display(StringType T);
        bool StrAssign(StringType &T, StringType chars);
        int StrCompare(StringType s, StringType t);
};

#endif // CUSTOMSTRING_H
