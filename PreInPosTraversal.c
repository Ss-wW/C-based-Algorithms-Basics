#include <stdio.h>
#include <stdlib.h>

#define LEN_trnode sizeof(struct trnode)
#define LEN_stacknode sizeof(struct stack)

typedef struct trnode
{
    int value;
    struct trnode *left;
    struct trnode *right;
} * TrNode;

TrNode newTrNode(int value);

TrNode newTrNode(int value)
{
    TrNode head = (TrNode)malloc(LEN_trnode);
    head->value = value;
    head->left = NULL;
    head->right = NULL;
    return head;
}

// 定义一个存储树节点的栈
typedef struct stack
{
    TrNode item;
    struct stack *next;
} * Stack;

Stack init_stack();
bool isEmptyStack(Stack head);
void push(Stack *head, TrNode item);
TrNode pop(Stack *head);

Stack init_stack()
{
    Stack head;
    head = NULL;
    return head;
}

bool isEmptyStack(Stack head)
{
    return head == NULL ? 1 : 0;
}

void push(Stack *head, TrNode item)
{
    Stack p = (Stack)malloc(LEN_stacknode);
    p->item = item;
    p->next = *head;
    *head = p;
}

TrNode pop(Stack *head)
{
    TrNode p = (TrNode)malloc(LEN_trnode);
    if (!isEmptyStack(*head))
    {
        p = (*head)->item;
        (*head) = (*head)->next;
        return p;
    }
}

// 递归版本的二叉树先序（中左右）、中序（左中右）、后序（左右中）遍历
// preOrderRecur、inOrderRecur、posOrderRecur
// 函数的返回值类型是 void
// 需要判断节点是否为空

void preOrderRecur(TrNode head);
void inOrderRecur(TrNode head);
void posOrderRecur(TrNode head);

void preOrderRecur(TrNode head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%3d ", head->value);
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void inOrderRecur(TrNode head)
{
    if (head == NULL)
    {
        return;
    }
    inOrderRecur(head->left);
    printf("%3d ", head->value);
    inOrderRecur(head->right);
}

void posOrderRecur(TrNode head)
{
    if (head == NULL)
    {
        return;
    }
    posOrderRecur(head->left);
    posOrderRecur(head->right);
    printf("%3d ", head->value);
}

// 非递归的二叉树遍历
// 需要将所有操作放在 if 里面，head 非空时进行操作，因为不能像递归一样使用 return 的方法了。
// 建立一个栈，将二叉树的头节点（根节点）放入栈中
// 先序遍历：弹出头节点，栈非空时，先压右再压左；
// 中序遍历：理解1）压栈考虑左节点，空节点触发出栈，出栈考虑右节点；
//          理解2）遇到一个节点，先压栈，然后考虑左节点，一直到空节点，开始弹出，每弹出一个节点，考虑该节点的右节点
// 后序遍历：两个栈 s1 和 s2；两个判断条件：s1 非空？head=pop(s1),push(head); head左右非空?先压左再压右. 
//          两个while循环,第二个while里 pop(s2)并打印
void preOrderUnRecur(TrNode head)
{
    if (head != NULL)
    {
        Stack s1 = init_stack();
        push(&s1, head);
        while (!isEmptyStack(s1))
        {
            head = pop(&s1);
            printf("%3d ", head->value);
            if (head->right != NULL)
            {
                push(&s1, head->right);
            }
            if (head->left != NULL)
            {
                push(&s1, head->left);
            }
        }
    }
    return;
}

void inOrderUnRecur(TrNode head)
{
    if (head != NULL)
    {
        Stack s1 = init_stack();
        while (!isEmptyStack(s1) || head != NULL)
        {
            if (head != NULL)
            {
                push(&s1, head);
                head = head->left;
            }
            else
            {
                head = pop(&s1);
                printf("%3d ", head->value);
                head = head->right;
            }
        }
    }
    return;
}

void posOrderUnRecur(TrNode head){
    if(head!=NULL){
        Stack s1 = (Stack)malloc(LEN_stacknode);
        Stack s2 = (Stack)malloc(LEN_stacknode);
        push(&s1,head);
        while (!isEmptyStack(s1) || head != NULL){
            head = pop(&s1);
            push(&s2,head);
            if (head->left != NULL){
                push(&s1,head->left);
            }
            if (head->right != NULL){
                push(&s1,head->right);
            }
        }
        while (!isEmptyStack(s2)){
            printf("%3d ",pop(&s2)->value);
        }
    }
    return;
}

int main()
{
    TrNode head = newTrNode(5);
    head->left = newTrNode(3);
    head->right = newTrNode(8);
    head->left->left = newTrNode(2);
    head->left->right = newTrNode(4);
    head->left->left->left = newTrNode(1);
    head->right->left = newTrNode(7);
    head->right->left->left = newTrNode(6);
    head->right->right = newTrNode(10);
    head->right->right->left = newTrNode(9);
    head->right->right->right = newTrNode(11);

    // recursive
    printf("=============== recursive ===============\n\n");
    printf("%-20s", "pre-order recur: ");
    preOrderRecur(head);
    printf("\n\n");
    printf("%-20s", "in-order: ");
    inOrderRecur(head);
    printf("\n\n");
    printf("%-20s", "pos-order: ");
    posOrderRecur(head);
    printf("\n\n");

    // Stack stHead = init_stack();
    // push(&stHead,head);
    // printf("%3d \n",stHead->item->value);
    // push(&stHead,head->left);
    // printf("%3d \n",stHead->item->value);
    // TrNode p = pop(&stHead);
    // printf("%3d \n",p->value);
    // printf("%3d \n",stHead->item->value);

    // unrecursive
    printf("=============== un-recursive ===============\n\n");
    printf("%-20s", "pre-order unrecur: ");
    preOrderUnRecur(head);
    printf("\n\n");
    printf("%-20s","in-order unrecur: ");
    inOrderUnRecur(head);
    printf("\n\n");
    printf("%-20s","pos-order unrecur: ");
    posOrderRecur(head);
    printf("\n\n");

    // hold the cmd window
    system("pause");
    return 0;
}