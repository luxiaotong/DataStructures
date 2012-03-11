#ifndef LINKLIST_H
#define LINKLIST_H
#include "Global.h"

class LinkNode
{
    public:
        IntType data;
        LinkNode * next;

};
class LinkList
{
    public:
        LinkNode * ListInit();
        LinkNode * ListInit2();
        LinkNode * ListInit3();
        int Locate(LinkNode * L, IntType x);
        int Length(LinkNode * L);
        void Display(LinkNode * link_a);
        LinkNode * Insert(LinkNode * link_a, IntType data);
        LinkNode * Delete(LinkNode * link, IntType data);
        LinkNode * Join(LinkNode *link_a, LinkNode *link_b);
        LinkNode * Join_23(LinkNode *link_a, LinkNode *link_b);
        LinkNode * Reverse(LinkNode * link_a);
        LinkNode * Intersect(LinkNode * link_a, LinkNode *link_b);
        LinkNode * Duplication_29(LinkNode * link_a, LinkNode * link_b, LinkNode * link_c);
};

#endif // LINKLIST_H
