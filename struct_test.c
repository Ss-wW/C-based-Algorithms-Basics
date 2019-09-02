#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)

typedef struct Node{
    int value;
    struct Node * next;
}Node;

int n;//每次新建一个节点，n的值加一，
//用于判断当前节点是否是第一个节点，
//如果是，则令head=p1；如果不是，则令p2->next=p1；
//上述head是指向链表头的指针，p1是用于开辟新节点的指针，p2是指向链表尾的指针
struct Node* newNode(int value){
    Node *tmp= (Node*)malloc(LEN);
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

// struct Node newNode2(int value){
//     Node tmp= (Node)malloc(sizeof(LEN)); 
//     tmp.value = value;
//     return tmp;
// }

int main(){
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    // Node* end = newNode(3); end.next = NULL;
    // Node head2 = newNode2(4);
    // head2.next = newNode2(5);
    // head2.next.next = newNode2(6)
    // head2.next.next.next = NULL;
    // head1->next->next->next=NULL;

    Node*p=head1;
    while(p!=NULL){
        printf("%d\n",p->value);
        p=p->next;
    }
    system("pause");
    return 0;
}