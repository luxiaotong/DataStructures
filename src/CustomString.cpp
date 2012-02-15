#include "CustomString.h"

void CustomString :: StrAssign(StringType &t, StringType s)
{
    if(!t)
        return;
    else if(strlen(t) < strlen(s))
        t = new char[strlen(s)];
    t = s;
    return;
}

int CustomString :: StrCompare(StringType s, StringType t)
{
    int i = 0, j = 0;
    int len1 = strlen(s);
    int len2 = strlen(t);
    while(i < len1 || j < len2)
    {
        if(s[i] > t[j])
            return 1;
        else if(s[i] < t[j])
            return -1;
        else{ i ++; j ++;}
    }
    if(i == len1 && j == len2)
        return 0;
    else if(i == len1)
        return -1;
    else if(j == len2)
        return 1;
}

int CustomString :: StrLength(StringType s)
{
    int i = 0;
    if(!s)
        return 0;
    while(1)
    {
        if(s[i] == '\0')
            return i;
        else
            i++;
    }
    return 0;
}

StringType CustomString :: Concat(StringType s, StringType t)
{
    int i = 0, j = 0;
    int len1 = StrLength(s);
    int len2 = StrLength(t);
    StringType tmp = new char[len1 + len2 + 1];
    while(i < len1)
    {
        tmp[i] = s[i];
        i ++;
    }
    while(j < len2)
    {
        tmp[i] = t[j];
        i ++;
        j ++;
    }
    tmp[i] ='\0';
    return tmp;
}


StringType CustomString :: SubString(StringType s, int start, int len)
{
    int sLen = StrLength(s);
    int i = 0, j = start - 1;
    StringType tmp = new char[sLen - len + 1];
    while(i < len)
    {
        tmp[i] = s[j];
        i ++;
        j ++;
    }
    tmp[i] = '\0';
    return tmp;
}

StringType CustomString :: Reverse(StringType s)
{
    int len = StrLength(s);
    int i = 0;
    StringType tmp = new char[len + 1];
    while(i < len)
    {
        tmp[i] = s[len - 1 - i];
        i ++;
    }
    tmp[i] = '\0';
    return tmp;
}

void CustomString :: getNext(StringType t, IntType (&next)[10])
{
    memset(next, 0, sizeof(next));
    int i = -1, j = 0;
    next[0] = -1;
    while(j < StrLength(t))
    {
        if(i == -1 || t[i] == t[j])
        {
            i ++;
            j ++;
            next[j] = i;
        }
        else
            i = next[i];
    }

}

bool CustomString :: KMP(StringType s, StringType t)
{
    //getNext
   IntType next[10];
   getNext(t, next);
    //kmp
    int i = 0, j = 0, len1 = StrLength(s), len2 = StrLength(t);
    while(i < len1 && j < len2)
    {
        if(j == -1 || s[i] == t[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == len2) return 1;
    else return 0;
    return 0;
}
void CustomString :: Replace(StringType &s, StringType t, StringType v)
{
    int start = 0, end = 0;
    return;
}
