#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2) return numsSize;
    int i = 1; // sequentially point to the next element
    int k = 1; // the position/number of non duplicate element; nums[0] considered;
    for(i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main()
{
    int nums[] = {1,1,2};
    int len = removeDuplicates(nums,3);
    for(int i=0;i<len;i++){
        printf("%d\t",nums[i]);
    }
    system("pause");
    return 0;
}