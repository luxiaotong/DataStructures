#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H
<<<<<<< HEAD

#include <iostream>
#include <cstring>
typedef char * StringType;

=======
typedef char * StringType;
typedef int IntType;
#include <iostream>
#include <cstring>
>>>>>>> ed7b7a031090c2300290dcf05c784efd8228439a
using namespace std;

class CustomString
{
    public:
<<<<<<< HEAD
        void Display(StringType T);
        bool StrAssign(StringType &T, StringType chars);
        int StrCompare(StringType s, StringType t);
=======
        void StrAssign(StringType &t, StringType s);
        int StrCompare(StringType s, StringType t);
        int StrLength(StringType s);
        StringType Concat(StringType s, StringType t);
        StringType SubString(StringType s, int start, int len);
        StringType Reverse(StringType s);
        void Replace(StringType &s, StringType t, StringType v);
        //void getNext(StringType s, IntType (&next) [10]);
        bool KMP(StringType s, StringType t);
>>>>>>> ed7b7a031090c2300290dcf05c784efd8228439a
};

#endif // CUSTOMSTRING_H
