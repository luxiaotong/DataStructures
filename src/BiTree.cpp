#include "BiTree.h"
//创建二叉树
BiTNode * BiTree::CreateBiTree()
{
    TreeType ch;
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

//递归 先序遍历
void BiTree::PreOrderTraverse(BiTNode * T)
{
    if(T){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//递归 中序遍历
void BiTree::InOrderTraverse(BiTNode * T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        cout << T->data;
        PreOrderTraverse(T->rchild);
    }
}

//递归 后序遍历
void BiTree::PostOrderTraverse(BiTNode * T)
{
    if(T){
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        cout << T->data;
    }
}

//非递归 先序创建二叉树
BiTNode * BiTree::CreateBiTreeNoRec()
{

    BiTNode * root = new BiTNode;
    stack<BiTNode **>s;
    TreeType ch;
    cin >> ch;
    if(ch == '#') {
        root = NULL;
    } else {
        root->data = ch;
        s.push(&(root->rchild));
        s.push(&(root->lchild));
        while(!s.empty()) {
            BiTNode **tmp = s.top();
            s.pop();
            cin >> ch;
            if(ch == '#') {
                *tmp = NULL;
            } else {
                *tmp = new BiTNode;
                (*tmp)->data = ch;
                s.push(&((*tmp)->rchild));
                s.push(&((*tmp)->lchild));
            }
        }
    }
    return root;
}
//非递归 层序创建二叉树
BiTNode * BiTree::CreateBiTreePreOrder()
{
    BiTNode * root = new BiTNode;
    queue<BiTNode *>q;
    bool isRight = false;
    TreeType ch;
    cin >> ch;
    if(ch == '#') {
        root = NULL;
    } else {
        root->data = ch;
        q.push(root);
        while(!q.empty()) {
            cin >>ch;
            BiTNode * tmp = q.front();
            if(!isRight) {
                isRight = true;
                if(ch == '#') {
                    tmp->lchild = NULL;
                } else {
                    tmp->lchild = new BiTNode;
                    tmp->lchild->data = ch;
                }
            }
            else {
                q.pop();
                isRight = false;
                if(ch == '#') {
                    tmp->rchild = NULL;
                } else {
                    tmp->rchild = new BiTNode;
                    tmp->rchild->data = ch;
                }
                if(tmp->lchild)
                    q.push(tmp->lchild);
                if(tmp->rchild)
                    q.push(tmp->rchild);
            }
        }
    }
    return root;
}
//非递归 先序遍历
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

//非递归 中序遍历
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

//非递归 后序遍历
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

//层序遍历
void BiTree::LevelOrderTraverse(BiTNode * T)
{
    int count = 0, refer = 1, width=16;
    queue<BiTNode *>q;
    while(T || !q.empty()) {

            count ++;
            if(count == 1)      cout << setw(width/2);
            else    cout << setw(width);
            if(T) {
                cout << T->data;
                q.push(T->lchild);
                q.push(T->rchild);
            } else {
                cout << ' ';
            }
            if(count == refer) {
                cout << endl;
                refer *= 2;
                count = 0;
                width /= 2;
            }
            T = q.front();
            q.pop();
            //cout << q.size() << endl;
    }
    return;
}

//递归     交换所有节点的左右子树
void BiTree::SwapTree(BiTNode * &T)
{
    queue<BiTNode *>q;
    BiTNode * tmp;
    if(T) {
        tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
        SwapTree(T->lchild);
        SwapTree(T->rchild);
    }
    return;
}

//递归  交换所有节点的左右子树
void BiTree::CountLeaf(BiTNode * T, int &count)
{
    if(T) {
        if(!T->lchild && !T->rchild)
            count ++;
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
    return;
}


//判断是不是完全二叉树
bool BiTree::IsCompleteBiTree(BiTNode * T)
{
    int flag = 0, level = 1, count = 0;
    queue<BiTNode *>q;
    while(T || !q.empty()) {
        count ++;
        if(T) {
            if(flag == 1)
                return false;
            q.push(T->lchild);
            q.push(T->rchild);
        } else {
            flag = 1;
        }
        if(count == level) {
            level *= 2;
            count = 0;
            flag = 0;
        }
        T = q.front();
        q.pop();
    }
    return true;
}
//动态查找
bool BiTree::BSTSearch(BSTNode * T, TreeType data, BSTNode * f, BSTNode * &p)
{
    if(!T) {
        p = f;
        return false;
    } else {
        if(T->data == data) {
            T->count ++;
            p = T;
            return true;
        }
        else if (T->data > data) {
             BSTSearch(T->lchild, data, T, p);
        } else if (T->data < data) {
             BSTSearch(T->rchild, data, T, p);
        }
    }
}

//动态创建查找树
void BiTree::BSTCreate(BSTNode * &T, char *data)
{
    BSTNode * p;
    int i = 0;
    while(i < strlen(data)) {
        if(!BSTSearch(T, data[i], NULL, p)) {
            BSTNode * s = new BSTNode;
            s->data = data[i];
            s->lchild = NULL;
            s->rchild = NULL;
            if(!p) {T = s;}
            else if(p->data > data[i]) {
                p->lchild = s;
            } else {
                p->rchild = s;
            }
        }
        i++;
    }
    return;
}
//显示查找树结果
void BiTree::BSTDisplay(BSTNode * T)
{
    if(T) {
        BSTDisplay(T->lchild);
        cout << T->data << " " << T->count << endl;
        BSTDisplay(T->rchild);
    }
}

void BiTree::BSTInsert(BSTNode * &root, char *data)
{
    int i = 0;
    while(i < strlen(data)) {
        if(root == NULL) {
            root = new BSTNode;
            root->data = data[i];
        }
        else {
            BSTNode * T = root;
            while(1) {
                if(T->data > data[i]) {
                        if(T->lchild == NULL){
                            T->lchild = new BSTNode;
                            T->lchild->data = data[i];
                            break;
                        } else {
                            T = T->lchild;
                        }
                } else if(T->data < data[i]) {
                        if(T->rchild == NULL) {
                            T->rchild = new BSTNode;
                            T->rchild->data = data[i];
                            break;
                        } else {
                            T = T->rchild;
                        }
                } else {
                        T->count ++;
                        break;
                }
            }
        }
        i++;
    }

}
