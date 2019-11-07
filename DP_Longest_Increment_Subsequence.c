// question: LIS
// input n as the length of the sequence arr;
// input the sequence arr
// output the longest increment sub-sequence within arr
// e.g. arr = {1,5,3,4,6,9,7,8}
// output should be 6
// 6 corresponds to {1,3,4,6,7,8}

#include <stdio.h>
#include <stdlib.h>

#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int main()
{
    int n = 8;
    int arr[] = {1,5,3,4,6,9,7,8};
    //int f[9] = {1};// nonzero value cannot be initialized such way.
    int f[n];
    for(int i=0;i<n;i++) f[i] = 1;
    int ans = 1;
    int x,p;
    for(x=0;x<n;x++){
        for(p=0;p<x;p++){
            if(arr[p]<arr[x]){
                f[x] = max(f[x],f[p]+1);
            }
        }
        printf("f[%d] = %d\n",x+1,f[x]);
    }
    for(x=1;x<=n;x++){
        // Frankly speaking, I cannot understand why not just print f[n].
        ans = max(ans,f[x]);
    }
    
    system("pause");
    return 0;
}