#ifndef BITREE_H
#define BITREE_H
#include "Global.h"
#include "Stack.h"
#include <iostream>
#include <cstring>
using namespace std;
class BiTNode
{
    public:
        CharType data;
        BiTNode * lchild;
        BiTNode * rchild;
};

class BiTree
{
    public:
        BiTNode * CreateBiTree();                                                  //�ݹ�     ����������
        void PreOrderTraverse(BiTNode * T);                                 //�ݹ�     �������
        void InOrderTraverse(BiTNode * T);                                   //�ݹ�     �������
        void PostOrderTraverse(BiTNode * T);                               //�ݹ�     �������
        BiTNode * CreateBiTreeNoRec();                                        //�ǵݹ� ����������
        void PreOrderTraverseNoRec(BiTNode * T);                       //�ǵݹ� �������
        void InOrderTraverseNoRec(BiTNode * T);                         //�ǵݹ� �������
        void PostOrderTraverseNoRec(BiTNode * T);                     //�ǵݹ� �������
};

#endif // BITREE_H
