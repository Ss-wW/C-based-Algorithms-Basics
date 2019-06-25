#include<stdio.h>
#include<stdlib.h>

void heapSort(int arr[], int len);
void heapInsert(int arr[], int index);
void heapify(int arr[], int index, int heapSize);
void swap(int arr[],int i, int j);
void heapSort(int arr[], int len){
    if (arr == NULL || len<2){
        return;
    }
    for (int i=0;i<len;i++){
        heapInsert(arr,i);
    }
    int heapSize = len;
    swap(arr,0,--heapSize);
    while (heapSize>0){
        heapify(arr,0,heapSize);
        swap(arr,0,--heapSize);
    }
    return;
}

void heapInsert(int arr[], int index){
    while (arr[index]>arr[(index-1)/2]){
        swap(arr,index,(index-1)/2);
        index = (index-1)/2;
    }
    return;
}

void heapify(int arr[], int index, int heapSize){
    int left = index*2+1;
    while(left<heapSize){
        int largest = left+1<heapSize && arr[left+1]>arr[left]?left+1:left;//注意left+1<heapSize不成立时，说明右子节点超范围，此时给largest赋值left
        largest = arr[index]>arr[largest]?index:largest;
        if (largest==index){
            break;
        }
        swap(arr,index,largest);
        index = largest;
        left = index*2+1;
    }
    return;
}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

int main(){
    int len;
    printf("The length of the random array is ");
    scanf("%d",&len);
    int Range;
    printf("The range of the random array is ");
    scanf("%d",&Range);    
    int*a=(int*)malloc(len*sizeof(int));
    for (size_t i = 0; i < len; i++)
    {
        a[i] = rand()%Range+1;
    }
    printf("before heapSort, the array is \n[");
    for (int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("]\n");
    heapSort(a,len);
    printf("after heapSort, the array is \n[");
    for (int i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("]\n");    
    system("pause");
    return 0;
}