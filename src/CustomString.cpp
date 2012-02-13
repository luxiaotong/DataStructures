#include "CustomString.h"

bool CustomString :: StrAssign(StringType &T, StringType chars)
{
    if(T)
        delete [] T;
    int len = strlen(chars);
    if(len <= 0)
        return false;
    else
    {
        T = new char[len];
        T = chars;
    }
    return true;
}

void CustomString :: Display(StringType T)
{
    cout << T << endl;
}

int CustomString :: StrCompare(StringType s, StringType t)
{
    int i = 0, j = 0;
    while(i < strlen(s) && j < strlen(t))
    {
        if(j > strlen(t) || s[i] > t[j])
            return 1;
        if(i > strlen(s) || s[i] < t[j])
            return -1;
        if(s[i]  == t[j])
        {
            if(i == strlen(s) && j == strlen(t))
                return 0;
            i++;
            j++;
        }
    }
}

