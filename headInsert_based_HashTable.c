#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode * next;
}*ListNodePtr;

ListNodePtr ListNode_init(int x){
    ListNodePtr tmp = (ListNodePtr)malloc(sizeof(struct ListNode));
    tmp->value = x;
    tmp->next = NULL;
    return tmp;
}


int hash_func(int key, int table_len){
    return key % table_len;
}

void insert_hash(ListNodePtr hash_table[], ListNodePtr Node, int table_len){
    int hash_key = hash_func(Node->value,table_len);
    Node->next = hash_table[hash_key];
    hash_table[hash_key] = Node;
}

bool search_hash(ListNodePtr hash_table[], int value, int table_len){
    int hash_key = hash_func(value,table_len);
    ListNodePtr head = hash_table[hash_key];
    while(head){
        if(head->value==value){
            return true;
        }
        head = head->next;
    }
    return false;
}

int main(){
    printf("Hello world!\n");
    int data_len = 8;
    int test[data_len] = {1,1,4,9,20,30,150,500};
    const int TABLE_LEN = 11;
    ListNodePtr hash_table[TABLE_LEN] = {0};
    // insert hash table
    for (int i = 0; i < data_len; i++){
        insert_hash(hash_table,ListNode_init(test[i]),TABLE_LEN);
    }
    printf("Hash table:\n");
    for(int i = 0; i < TABLE_LEN; i++){
        printf("[%d]:",i);
        ListNodePtr head = hash_table[i];
        while(head){
            printf("->%d",head->value);
            head = head->next;
        }
        printf("\n");
    }
    // search 
    printf("Search Test:\n");
    for(int i = 0; i < 10; i++){
        printf("%d is %s the hash table.\n",i,search_hash(hash_table,i,TABLE_LEN) ? "in" : "not in");
    }
    system("pause");
    return 0;
}