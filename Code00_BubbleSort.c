#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void myBubbleSort(int arr[], int len){
    if (arr==NULL || len < 2){
        return;
    }
    for (int e = len-1;e > 0;e--){
        for(int i=0;i<e;i++){
            if (arr[i]>arr[i+1]){
                swap(arr+i,arr+i+1);
            }
        }
    }
    return;
}

int* generateRandomArray(int len){
    int * p = (int*)malloc(len*sizeof(int));
    for (int i=0;i<len;++i){
        *(p+i) = rand()%100;
    }
    return p;
}
int main(){
    int len = 6;
    time_t t;
    srand((unsigned int)time(&t));
    int * arr = generateRandomArray(len);
    //int arr[len] = {66,23,30,1,47,3};
    printf("generate random array with length = %d\n",len);
    for(int i = 0;i < len; ++i){
        printf("%-4d",*(arr+i));
    }
    printf("\n");
    myBubbleSort(arr,len);
    printf("after bubble sort\n");
    for(int i = 0;i < len; ++i){
        printf("%-4d",*(arr+i));
    }
    printf("\n");
    system("pause");
    return 0;
}
