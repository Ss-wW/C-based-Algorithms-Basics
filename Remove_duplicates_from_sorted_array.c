#include<stdio.h>
#include<stdlib.h>

int arr_left_shift(int* nums,int numsSize,int pos){
    for(int i = pos;i<numsSize-1;i++){
        nums[i] = nums[i+1];
    }
    return numsSize-1;
}

int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    while(i<numsSize-1){
        if (nums[i]==nums[i+1]){
            numsSize = arr_left_shift(nums,numsSize,i);
        }
        else{
            i++;
        }
    }
    return numsSize;
}

int main()
{
    int nums[] = {0,0,0,1,1,1,2,2,3,3,4,4};
    int len = removeDuplicates(nums,11);
    for(int i=0;i<len;i++){
        printf("%d\t",nums[i]);
    }
    system("pause");
    return 0;
}