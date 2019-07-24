#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN sizeof(struct Node)

typedef struct Node
{
    int value;
    struct Node *next;
} * PNode;

PNode newNode(int value)
{
    PNode tmp = (PNode)malloc(LEN);
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void PrintNode(PNode head)
{
    PNode p = head;
    int count = 20;
    while (p != NULL)
    {
        printf("%d\n", p->value);
        p = p->next;
        if (count-- < 0)
            return;
    }
    return;
}

PNode getIntersectNode(PNode head1, PNode head2);
PNode getLoopNode(PNode head);
PNode noloop(PNode head1, PNode head2);
PNode bothloop(PNode head1, PNode loop1, PNode head2, PNode loop2);

PNode getIntersectNode(PNode head1, PNode head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;
    PNode loop1 = getLoopNode(head1);
    PNode loop2 = getLoopNode(head2);
    if (loop1 == NULL && loop2 == NULL)
        return noloop(head1, head2);
    if (loop1 != NULL && loop2 != NULL)
        return bothloop(head1, loop1, head2, loop2);
    // if one of head1 and head2 is noloop, and the other one is loop,
    // then there must has no intersectnNode for the two single direction linklist.
    return NULL;
}

PNode getLoopNode(PNode head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;

    PNode SL = head->next;
    PNode FS = head->next->next;
    while (SL != FS)
    {
        if (FS->next == NULL || FS->next->next == NULL)
            return NULL;
        SL = SL->next;
        FS = FS->next->next;
    }
    FS = head;
    while (FS != SL)
    {
        FS = FS->next;
        SL = SL->next;
    }
    return FS;
}

PNode noloop(PNode head1, PNode head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;
    PNode cur1 = head1;
    PNode cur2 = head2;
    int n = 0;
    while (cur1->next != NULL)
    {
        // do not let cur1 link to the unknown node outside of the linklist.
        // so, use (cur1->next != NULL) instead of (cur1 != NULL)
        n++;
        cur1 = cur1->next;
    }
    while (cur2->next != NULL)
    {
        n--;
        cur2 = cur2->next;
    }
    if (cur1 != cur2)
        return NULL;
    // two noloop linklists can only intersect with the shape of "Y"
    // meaning they must share the same last node.

    cur1 = n > 0 ? head1 : head2;
    cur2 = n > 0 ? head2 : head1;
    //let cur1 link to the longer linklist
    // if n > 0, head1 length > head2 length,
    // if n == 0, it's ok.
    // if n < 0, the following procedure needs abs(n)
    n = fabs(n);
    while (n > 0)
    {
        cur1 = cur1->next;
        n--;
    }
    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

PNode bothloop(PNode head1, PNode loop1, PNode head2, PNode loop2)
{
    PNode cur1 = NULL;
    PNode cur2 = NULL;
    if (loop1 == loop2)
    {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = fabs(n);
        while (n != 0)
        {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else
    {
        cur1 = loop1->next;
        while (cur1 != loop1)
        {
            if (cur1 == loop2)
            {
                return loop1;
            }
            cur1 = cur1->next;
        }
        return NULL;
    }
}

int main()
{
    PNode head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    PNode head2 = newNode(0);
    head2->next = newNode(9);
    head2->next->next = newNode(8);
    head2->next->next->next = head1->next->next->next->next->next;
    printf("%d\n", getIntersectNode(head1, head2)->value);

    head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = head1->next->next->next;

    head2 = newNode(0);
    head2->next = newNode(9);
    head2->next->next = newNode(8);
    head2->next->next->next = head1->next;
    printf("%d\n", getIntersectNode(head1, head2)->value);

    head2 = newNode(0);
    head2->next = newNode(9);
    head2->next->next = newNode(8);
    head2->next->next->next = head1->next->next->next->next->next;
    printf("%d\n", getIntersectNode(head1, head2)->value);

    system("pause");
    return 0;
}