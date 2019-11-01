#include<stdio.h>
#include<stdlib.h>


struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* ListInitial(struct ListNode* head){
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    head->val = 0;
    return head;
}
struct ListNode* newListNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// struct ListNode* ListCreat_Tail(struct ListNode** head,int* nums, int len){
//     // nums is an array, len is the length of nums
//     // creat a link list according to the input nums
//     int i;
//     if(*head == NULL){
//         *head = (struct ListNode*)malloc(sizeof(struct ListNode));
//     }
//     struct ListNode* r = (*head);// the pointer to the tail;
//     for(i = 0;i<len;i++){
//         struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//         newNode->val = nums[i];
//         newNode->next = NULL;
//         r->next = newNode;
//         r = r->next;
//     }
//     return *head;
// }


struct ListNode* ListCreat_Tail(struct ListNode** head,int* nums, int len){
    // nums is an array, len is the length of nums
    // creat a link list according to the input nums
    int i;
    if(*head == NULL){
        *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    }
    struct ListNode* r = (*head);// the pointer to the tail;
    r->val = nums[0];
    r->next = NULL;

    for(i = 1;i<len;i++){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;
        r->next = newNode;
        r = r->next;
    }
    return *head;
}

struct ListNode* removeElements(struct ListNode* head, int val){
    if((head) == NULL) return head;
    struct ListNode* p1 = head;
    struct ListNode* p2 = p1;
    while(p2->val == val){
        p2 = p2->next;
        if(p2 == NULL) return p2;
    }
    p1 = p2;
    // p2->val not equal to val
    while(p2->next !=NULL){
        while(p2->next->val != val && p2->next != NULL){
            p2 = p2->next;
            if(p2->next == NULL){
                return p1;
            }
        }
        // p2->next == NULL or p2->next->val == val
        p2->next = p2->next->next;
    }
    return p1;
}

int main()
{
    struct ListNode* link_list = NULL;
    //link_list = newListNode(1);
    //link_list->next = newListNode(3);
    // link_list->next->next = newListNode(2);
    int nums[] = {1,6,1,4,5,6};
    //link_list = ListInitial(link_list);
    ListCreat_Tail(&link_list,nums,6);
    int val = 1;
    link_list = removeElements(link_list,val);
    system("pause");
    return 0;
}