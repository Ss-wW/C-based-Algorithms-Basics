#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType; //线性表的基本数据类型
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *Next;
} Node, *LinkList;

Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p;
    p = L->Next;
    int j = 1;
    while (p && j < i)
    {
        p = p->Next;
        j++;
    }

    if (p == NULL || j > i)
    {
        // 为什么要判断 j>i 呢？因为如果i为负数，链表不为空，没有这个判断的话，if后面的代码还会执行，就会返回错误的结果。
        return FALSE;
    }
    *e = p->data;
    return TRUE;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList p, s;
    int j = 1;
    p = *L;
    while (p && j < i) // p is not NULL and j is smaller than the positon to insert
    {
        p = p->Next;
        j++;
    }
    if (!p || j > i) // p == NULL 
    {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->Next = p->Next;
    p->Next = s;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j = 1;
    LinkList p, q;
    p = (*L)->Next;

    while (p->Next && j < i)
    {
        p = p->Next;
        j++;
    }
    if (!(p->Next) || j > i)
    {
        return ERROR;
    }
    q = p->Next;
    p->Next = q->Next;
    *e = q->data;
    free(q);
    return OK;
}

Status CreatListHead(LinkList *L, int n)
{
    LinkList p;
    int j;
    srand(time(0)); // 初始化随机种子
    (*L) = (LinkList)malloc(sizeof(Node));
    (*L)->Next = NULL;
    for (j = 0; j < n; j++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->Next = (*L)->Next; // 为什么不是 p->Next = (*L) ？
        (*L)->Next = p;
    }
    return OK;
}

Status CreatListTail(LinkList *L, int n)
{
    LinkList p,r;//  p 是临时结点， r指向尾结点
    int j;
    srand(time(0));
    (*L) = (LinkList)malloc(sizeof(Node));
    (*L)->Next = NULL;
    r = *L;
    for(j=0;j<n;j++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->Next = NULL;
        r->Next = p; // important 
        r = p; // important
    }
    r->Next = NULL;
    return OK;
}

Status PrintList(LinkList L){
    ElemType e;
    int pos = 1;
    while (GetElem(L, pos, &e))
    {
        printf("the %d-th element is %d\n", pos, e);
        pos++;
    }    
    return OK;
}

int main()
{
    LinkList L = NULL;
    ElemType e;
    int Len = 5;
    CreatListHead(&L, Len);
    PrintList(L);
    int pos;
    for (pos = 1; pos < 4; pos++)
    {
        ListInsert(&L, pos, pos);
    }
    PrintList(L);
    pos = 2;
    if (ListDelete(&L, pos - 1, &e))
    {
        printf("delete the %d-th element as %d\n", pos, e);
        PrintList(L);
    }
    CreatListTail(&L,Len);
    PrintList(L);
    system("pause");
    return 0;
}
