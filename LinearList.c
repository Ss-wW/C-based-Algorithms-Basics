#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 20 // 线性表的最大长度
// 与 Status 相关的 4 种状态，OK，ERROR，TRUE，FALSE
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType; //线性表的基本数据类型
typedef int Status;
typedef struct List{
    // 这种定义的是链式结构
    ElemType e;
    struct List* next;
}List;

typedef struct{
    //定义线性表的顺序结构
    ElemType data[MAXSIZE];//顺序结构的线性表，用数组实现
    int length; // 线性表的当前长度
}SqList; //顺序表 Sequencial List

typedef struct Node{
    ElemType data;// 数据域
    struct Node* Next; // 指针域
}Node;

typedef struct Node* LinkList;

bool ListEmpty(List L);

List* InitList(){
    List* L = NULL;
    return L;
}

bool ListEmpty(List L){
    return &L == NULL ? true:false;
}

void ClearList(List* L){
    L = NULL;
    return;
}

Status GetElem(SqList L, int i, ElemType *e){
    // GetElem 函数的返回值是Status状态码，为了返回元素的值，用指针作为输入参数
    if(L.length == 0 || i<1 || i > L.length){
        //  两种可能的错误情况：空表，不合法的索引值
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

int LocateElem(List L, ElemType e){
    List* p = (List*)malloc(sizeof(List));
    p = &L;    
    int i = 1;
    while(p != NULL){
        if(p->e == e){
            return i;
        }
        else{
            i++;
            p = p->next;
        }
    }
    return 0;
}

Status ListInsert(SqList* L, int i, ElemType e){
    // 判断表是否已经满了
    if(L->length == MAXSIZE){
        return ERROR; // 不与索引错误写在一起，因为后期可以对线性表扩容从而解决该错误
    }
    if(i<1 || i > L->length+1){
        //  不合法的索引值, 注意 i 等于 length+1 时也是可以的
        return ERROR;
    }
    for(int k = L->length-1;k>=i-1;k--){
        // 从第 i 个元素开始，后续元素依次右移；
        // 从后往前检索，并移位，若先移动前面的元素，可能会覆盖后面的元素
        L->data[k+1] = L->data[k];       
    }
    // 插入新的元素
    L->data[i-1] = e;
    // 线性表当前长度加一
    L->length++;

    return OK;
}

Status ListDelete(SqList* L, int i, ElemType*e){
    if(L->length == 0){
        return ERROR;
    }
    if(i<1 || i>L->length){
        return ERROR;
    }
    *e = L->data[i-1];
    for(int k=i-1;k<L->length-1;k++){
        L->data[k] = L->data[k+1];
    }
    L->length--;
    return OK;    
}

int ListLength(List L){
    List* p = (List*)malloc(sizeof(List));
    p = &L;    
    int i = 0;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}

int main(){
    printf("Hello World!\n");
    SqList A = {{1,3,5},3};//结构体变量 A 及其内部成员变量 data，length 的定义 （注意两组{}）
    SqList B = {{3,6},2};
    ElemType e;
    int i = 2;
    if(GetElem(A,i,&e)){
        printf("OK, the %dth element in A is %d\n",i,e);
    }
    e = 5;
    if(ListInsert(&A,i,e)){
        printf("the length of A is %d\n",A.length);
        for(i=0;i<A.length;i++){
            printf("%d\t",A.data[i]);
        }
    }
    printf("\n",A.data[i]);
    int pos = 1;
    if(ListDelete(&A,pos,&e)){
        printf("%d in A[%d] is deleted\n",e,pos);
        printf("the length of A is %d\n",A.length);
        for(i=0;i<A.length;i++){
            printf("%d\t",A.data[i]);
        }       
    }
    system("pause");
    return 0;
}