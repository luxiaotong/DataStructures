#ifndef BITREE_H
#define BITREE_H
#include "Global.h"
#include "Stack.h"
#include <iostream>
using namespace std;
class BiTNode
{
    public:
        TreeType data;
        BiTNode * lchild;
        BiTNode * rchild;
};

class BSTNode
{
    public:
        TreeType data;
        int count;
        BSTNode * lchild;
        BSTNode * rchild;
        BSTNode() {count = 1;lchild = NULL; rchild = NULL;}
        ~BSTNode();
};

class BiTree
{
    public:
        BiTNode * CreateBiTree();                                                  //�ݹ�     ����������
        void PreOrderTraverse(BiTNode * T);                                 //�ݹ�     �������
        void InOrderTraverse(BiTNode * T);                                   //�ݹ�     �������
        void PostOrderTraverse(BiTNode * T);                               //�ݹ�     �������
        BiTNode * CreateBiTreeNoRec();                                        //�ǵݹ� ���򴴽�������
        BiTNode * CreateBiTreePreOrder();                                    //�ǵݹ� ���򴴽�������
        void PreOrderTraverseNoRec(BiTNode * T);                       //�ǵݹ� �������
        void InOrderTraverseNoRec(BiTNode * T);                         //�ǵݹ� �������
        void PostOrderTraverseNoRec(BiTNode * T);                     //�ǵݹ� �������
        void LevelOrderTraverse(BiTNode * T);                              //�ǵݹ� �������
        void SwapTree(BiTNode * &T);                                          //�ݹ�     �������нڵ����������
        void CountLeaf(BiTNode * T, int &count);                         //�ݹ�     �������нڵ����������
        bool IsCompleteBiTree(BiTNode * T);                                 //�ж��ǲ�����ȫ������
        bool BSTSearch(BSTNode * T, TreeType data, BSTNode * f, BSTNode *&p);                    //��̬������
        void BSTCreate(BSTNode * &T, char *data);                      //��̬����������
        void BSTDisplay(BSTNode * T);                                          //��ʾ���������
        void BSTInsert(BSTNode * &T, char * data);                      //��̬����������
};

#endif // BITREE_H
