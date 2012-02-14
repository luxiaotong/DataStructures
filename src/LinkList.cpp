#include <iostream>
#include "LinkList.h"

using namespace std;
//�Զ���ʼ������
LinkNode * LinkList :: ListInit()
{
    LinkNode *head = new LinkNode;
    LinkNode *p = head;

    for(int i = 0; i < 10; i++)
    {

        p -> next = new LinkNode;
        p = p -> next;
        p -> data = i + 1;
    }
    p -> next = NULL;
    return head;
}
//�ֶ���ʼ������
LinkNode * LinkList :: ListInit2()
{
    IntType data;
    LinkNode *head = new LinkNode;
    LinkNode *p = head;
    p -> next = NULL;
    cout << "insert the data to link:" << endl;
    while(1)
    {
        cin >> data;
        if(data == -1) break;
        p = this->Insert(p, data);
    }
    return head;
}
//�Զ���ʼ��ѭ������
LinkNode * LinkList :: ListInit3()
{
    LinkNode *head = new LinkNode;
    LinkNode *p = head;

    for(int i = 0; i < 10; i++)
    {

        p -> next = new LinkNode;
        p = p -> next;
        p -> data = i + 1;
    }
    p -> next = head->next;
    return head;
}
//��λĳһ��ֵ�������е�λ��
int LinkList :: Locate(LinkNode * L, IntType x)
{
    LinkNode *p = L -> next;
    for(int i = 0; p != NULL; i++, p = p -> next)
        if(p -> data == x)
            return i;
    return -1;
}
//������ĳ���
int LinkList :: Length(LinkNode * L)
{
    int len = 0;
    LinkNode * p = L -> next;
    for(; p != NULL; p = p -> next)
        len++;
    return len;
}
//��������a��b
LinkNode * LinkList :: Join(LinkNode *link_a, LinkNode *link_b)
{
    LinkList l;
    LinkNode *head = NULL;
    LinkNode *p = NULL;
    int len_a = l.Length(link_a);
    int len_b = l.Length(link_b);
    if(len_a <= len_b)
    {
        head = link_a;
        p = head;
        while(p -> next !=NULL)
            p = p -> next;
        p -> next = link_b -> next;
    }
    else
    {
        head = link_b;
        p = head;
        while(p -> next !=NULL)
            p = p -> next;
        p -> next = link_a -> next;
    }
    return head;
}
//��������һ���µĽڵ�
LinkNode * LinkList :: Insert(LinkNode * link_a, IntType data)
{
    LinkNode * p = link_a;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = new LinkNode;
    p = p -> next;
    p -> data = data;
    p -> next = NULL;
    return link_a;
}
//ɾ�������ֵ��ͬ�Ľڵ�
LinkNode * LinkList :: Delete(LinkNode * link, IntType data)
{
    LinkNode * p = link;
    LinkNode * tmp = NULL;
    while(p->next != NULL)
    {
        tmp = p->next;
        if(tmp->data == data)
        {
            if(tmp->next != NULL)
                p->next = p->next->next;
            else
                p->next = NULL;
        }
        else
            p = p->next;
    }
    return link;
}
//��ӡ����
void LinkList :: Display(LinkNode * link_a)
{
    if(this->Length(link_a) == 0)
    {
        cout << 0;
    }
    else
    {
        LinkNode * p = NULL;
        for(p = link_a -> next; p != NULL; p = p -> next)
            cout << p -> data << " ";
        cout << endl;
    }
    return;
}
//�Ե�����ʵ�־͵�����
LinkNode * LinkList :: Reverse(LinkNode * link_a)
{
    LinkNode * head = new LinkNode;
    LinkNode * p1 = link_a -> next;
    LinkNode * p2 = NULL;
    LinkNode * p3 = NULL;
    while(p1)
    {
        p3 = p2;
        p2 = p1;
        p1 = p1 -> next;
        p2 -> next = p3;
    }
    p3 = p2;
    p2 = head;
    p2 -> next = p3;
    //cout << p1 -> data << " " << p2 -> data << endl;
    return p2;
}
//2.23�ϲ���ʵ��
LinkNode * LinkList :: Join_23(LinkNode *link_a, LinkNode *link_b)
{
    LinkNode *head = new LinkNode;
    LinkNode * tmp = head;
    LinkNode * p1 = link_a -> next;
    LinkNode * p2 = link_b -> next;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data <= p2->data)
        {
            tmp->next = p1;
            p1 = p1->next;
        }
        else
        {
            tmp->next = p2;
            p2 = p2->next;
        }
        tmp = tmp->next;
    }
    if(p2 != NULL)
        tmp->next = p2;
    else
        tmp->next =p1;

    return head;
}
LinkNode * LinkList :: Intersect(LinkNode * link_a, LinkNode * link_b)
{
    LinkNode * pa = link_a->next;
    LinkNode * pb = link_b->next;
    LinkNode * head = new LinkNode;
    LinkNode * p = head;

    while(pa != NULL && pb != NULL)
    {
        if(pa->data == pb->data)
        {
            p->next = pa;
            p = p->next;
            pa = pa->next;
            pb = pb->next;
        }
        else if(pa->data > pb->data)
        {
            pb = pb->next;
        }
        else
        {
            pa = pa->next;
        }
    }
    p->next = NULL;
    return head;
}
LinkNode * LinkList :: Duplication_29(LinkNode * link_a, LinkNode * link_b, LinkNode * link_c)
{
    LinkNode *pa = link_a;
    LinkNode *pb = link_b->next;
    LinkNode *pc = link_c->next;
    LinkNode *tmp = pa->next;
    while(pa != NULL && pb != NULL && pc != NULL)
    {
        if(tmp->data == pb->data && tmp->data == pc->data)
        {
            if(tmp->next == NULL)
            {
                pa->next = NULL;
                break;
            }
            pa->next = pa->next->next;
            tmp = pa->next;
            pb = pb->next;
            pc = pc->next;
        }
        else if(tmp->data < pb->data || tmp->data < pc->data)
        {
            pa = pa->next;
            tmp = tmp->next;
        }
        else if(tmp->data > pb->data)
        {
            pb = pb->next;
        }
        else if(tmp->data > pc->data)
        {
            pc = pc->next;
        }
    }
    return link_a;
}
