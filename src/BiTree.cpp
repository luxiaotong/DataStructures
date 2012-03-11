#include "BiTree.h"
//����������
BiTNode * BiTree::CreateBiTree()
{
    CharType ch;
    cin>>ch;
    if(ch == '#') {
        return NULL;
        //cout << "error" << endl;
    } else {
        BiTNode * T = new BiTNode;
        T->data = ch;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
        return T;
    }
}

//�ݹ� �������
void BiTree::PreOrderTraverse(BiTNode * T)
{
    if(T){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//�ݹ� �������
void BiTree::InOrderTraverse(BiTNode * T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        cout << T->data;
        PreOrderTraverse(T->rchild);
    }
}

//�ݹ� �������
void BiTree::PostOrderTraverse(BiTNode * T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        cout << T->data;
    }
}

//�ǵݹ� ����������
BiTNode * BiTree::CreateBiTreeNoRec()
{
    Stack s;
    s.InitStack(s);
    BiTNode * tmp = new BiTNode;
    CharType data;
    cin >> data;
    if(data == '#') {
        return NULL;
    } else {
        BiTNode * T = new BiTNode;
        T->lchild = new BiTNode;
        T->rchild = new BiTNode;
        T->data = data;
        s.Push(s, T->rchild);
        s.Push(s, T->lchild);
        while(!s.StackEmpty(s)) {
            cin >> data;
            if(data == '#') {
                s.Pop(s, tmp);
                tmp = NULL;
            } else {
                s.Pop(s, tmp);
                tmp->data = data;
                tmp->lchild = new BiTNode;
                tmp->rchild = new BiTNode;
                s.Push(s, tmp->rchild);
                s.Push(s, tmp->lchild);
            }
        }
        return T;
    }
}

//�ǵݹ� �������
void BiTree::PreOrderTraverseNoRec(BiTNode * T)
{
    Stack s;
    s.InitStack(s);
    while(T || !s.StackEmpty(s)) {
        if(T) {
            cout << T->data;
            s.Push(s, T->rchild);
            T = T->lchild;
        } else {
            s.Pop(s, T);
        }
    }
    return;
}

//�ǵݹ� �������
void BiTree::InOrderTraverseNoRec(BiTNode * T)
{
    Stack s;
    s.InitStack(s);
    while(T || !s.StackEmpty(s)) {
        while(T) {
            s.Push(s, T);
            T = T->lchild;
        }
        if(!s.StackEmpty(s)) {
            s.Pop(s, T);
            cout << T->data;
            T = T->rchild;
        }
    }
    return;
}

//�ǵݹ� �������
void BiTree::PostOrderTraverseNoRec(BiTNode * T)
{
    Stack s;
    s.InitStack(s);
    while(T || !s.StackEmpty(s)) {
        if(T->lchild) {
            s.Push(s, T);
            s.Push(s, T->rchild);
            T = T->lchild;
        } else {
            cout << T->data;
            s.Pop(s, T);
        }
    }
    return;
}
