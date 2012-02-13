#include "Sequence.h"
#include <iostream>
using namespace std;

void Sequence :: SeqInit(IntType *arr)
{
    for(int i = 0; i < LEN; i++)
    {
        cin >> arr[i];
    }
    return;
}
void Sequence :: display(IntType arr[])
{
    int len;
    GET_ARRAY_LEN(arr, len);
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}
char * Sequence :: compare_12(IntType arrA[], IntType arrB[])
{
    int lenA, lenB;
    GET_ARRAY_LEN(arrA, lenA);
    GET_ARRAY_LEN(arrB, lenB);
    int i = 0;
    while(i < lenA || i < lenB)
    {
        if(arrA[i] == arrB[i])
            i++;
        else if(arrA[i] > arrB[i])
            return ">";
        else
            return "<";
    }
    return "";
}
