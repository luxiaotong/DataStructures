#include "Luxiaotong.h"

//���ʽ��ֵ�õ����ж����ȼ�
//tmp1Ϊջs1�е�ջ��Ԫ��,tmp2Ϊ��ǰ������������
IntType Luxiaotong :: Precede(IntType tmp1, IntType tmp2)
{
    int key1, key2;
    char arr[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                                {'>', '>', '<', '<', '<', '>', '>'},
                                {'>', '>', '>', '>', '<', '>', '>'},
                                {'>', '>', '>', '>', '<', '>', '>'},
                                {'<', '<', '<', '<', '<', '=', ' '},
                                {'>', '>', '>', '>', ' ', '>', '>'},
                                {'<', '<', '<', '<', '<', ' ', '='}};
    switch(tmp1)
    {
        case '+' : key1 = 0; break;
        case '-' : key1 = 1; break;
        case '*' : key1 = 2; break;
        case '/' : key1 = 3; break;
        case '(' : key1 = 4; break;
        case ')' : key1 = 5; break;
        case '#' : key1 = 6; break;
    }
    switch(tmp2)
    {
        case '+' : key2 = 0; break;
        case '-' : key2 = 1; break;
        case '*' : key2 = 2; break;
        case '/' : key2 = 3; break;
        case '(' : key2 = 4; break;
        case ')' : key2 = 5; break;
        case '#' : key2 = 6; break;
    }
    return arr[key1][key2];
}

//���ܵ����������
void Luxiaotong :: Display(StringType prompt)
{
    if(!prompt)
        cout << "display error!" << endl;
    else {
        cout << endl;
        cout << "==========" << prompt << "==========" << endl;
    }
}
