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
        BiTNode * CreateBiTree();                                                  //递归     创建二叉树
        void PreOrderTraverse(BiTNode * T);                                 //递归     先序遍历
        void InOrderTraverse(BiTNode * T);                                   //递归     中序遍历
        void PostOrderTraverse(BiTNode * T);                               //递归     后序遍历
        BiTNode * CreateBiTreeNoRec();                                        //非递归 创建二叉树
        void PreOrderTraverseNoRec(BiTNode * T);                       //非递归 先序遍历
        void InOrderTraverseNoRec(BiTNode * T);                         //非递归 中序遍历
        void PostOrderTraverseNoRec(BiTNode * T);                     //非递归 后序遍历
};

#endif // BITREE_H
