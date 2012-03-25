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

//约瑟夫环
void Sequence::Josephus(int num, int start, int out)
{
    int i = 0;
    int arr[num];
    int k = num;
    int id = start;
    for(i = 0; i < num; i++) {
        arr[i] = i + 1;
    }
    i = 1;
    while(1) {
        if(i % out == 0) {
            Kickout(&$arr, id);
            i --;
            k --;
        }
        i ++;
        if(id == k) {
            id = 0;
        } else {
            id ++;
        }
    }
}
