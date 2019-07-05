#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Node)

typedef struct Node{
    int value;
    struct Node * next;
}*PNode;

PNode newNode(int value){
    PNode tmp= (PNode)malloc(LEN);
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void PrintNode(PNode head){
    PNode p=head;
    int count = 20;
    while(p!=NULL){
        printf("%d\n",p->value);
        p=p->next;
        if (count-- < 0) return;
    }
    return;
}

PNode getIntersectNode(PNode head1, PNode head2);
PNode getLoopNode(PNode head);
PNode noloop(PNode head1, PNode head2);
PNode bothloop(PNode head1, PNode head2);

PNode getIntersectNode(PNode head1, PNode head2){
    if (head1 ==NULL || head2 ==NULL)return NULL;
    PNode loop1 = getLoopNode(head1);
    PNode loop2 = getLoopNode(head2);
    if (loop1 == NULL && loop2 == NULL) return noloop(head1,head2);
    if (loop1 != NULL && loop2 != NULL) return bothloop(head1,head2);
    // if one of head1 and head2 is noloop, and the other one is loop,
    // then there must has no intersectnNode for the two single direction linklist.
    return NULL;
}

PNode getLoopNode(PNode head){
    if (head == NULL || head->next == NULL || head->next->next == NULL) return NULL;

    PNode SL = head->next;
    PNode FS = head->next->next;
    while(SL != FS){
        if (FS->next == NULL || FS->next->next == NULL) return NULL;
        SL = SL->next;
        FS = FS->next->next;
    }
    FS = head;
    while(FS != SL){
        FS = FS->next;
        SL = SL->next;
    }
    return FS;
}

PNode noloop(PNode head1, PNode head2){
    
}

PNode bothloop(PNode head1, PNode head2){

}



int main(){
    PNode head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(4);
    head1->next->next->next->next = newNode(5);
    head1->next->next->next->next->next = newNode(6);
    head1->next->next->next->next->next->next = newNode(7);
    head1->next->next->next->next->next->next->next = head1->next->next->next;

    PNode loop1 = getLoopNode(head1);
    
    if (loop1 != NULL) printf("Loop node with value = %d exists.\n",loop1->value);
    else printf("No Loop node.\n");

    PrintNode(head1);

    system("pause");
    return 0;
}