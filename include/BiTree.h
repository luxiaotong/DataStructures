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
        BiTNode * CreateBiTree();                                                  //递归     创建二叉树
        void PreOrderTraverse(BiTNode * T);                                 //递归     先序遍历
        void InOrderTraverse(BiTNode * T);                                   //递归     中序遍历
        void PostOrderTraverse(BiTNode * T);                               //递归     后序遍历
        BiTNode * CreateBiTreeNoRec();                                        //非递归 先序创建二叉树
        BiTNode * CreateBiTreePreOrder();                                    //非递归 层序创建二叉树
        void PreOrderTraverseNoRec(BiTNode * T);                       //非递归 先序遍历
        void InOrderTraverseNoRec(BiTNode * T);                         //非递归 中序遍历
        void PostOrderTraverseNoRec(BiTNode * T);                     //非递归 后序遍历
        void LevelOrderTraverse(BiTNode * T);                              //非递归 层序遍历
        void SwapTree(BiTNode * &T);                                          //递归     交换所有节点的左右子树
        void CountLeaf(BiTNode * T, int &count);                         //递归     交换所有节点的左右子树
        bool IsCompleteBiTree(BiTNode * T);                                 //判断是不是完全二叉树
        bool BSTSearch(BSTNode * T, TreeType data, BSTNode * f, BSTNode *&p);                    //动态查找树
        void BSTCreate(BSTNode * &T, char *data);                      //动态创建查找树
        void BSTDisplay(BSTNode * T);                                          //显示查找树结果
        void BSTInsert(BSTNode * &T, char * data);                      //动态创建查找树
};

#endif // BITREE_H
