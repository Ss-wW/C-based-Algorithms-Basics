#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArray(int*arr,int len){
    for (int j = 0; j < len; j++)
    {
        if (arr[j] == 0)
        {
            break;
        }
        printf("%d   ", arr[j]);
    }
    printf("\n");
    return;
}

int getData(char* p,int * arr){
    printf("%s\n",p);
    if(strchr(p,'{')==NULL){
        // C 库函数 char *strrchr(const char *str, int c) 在参数 str 所指向的字符串中搜索最后一次出现字符 c（一个无符号字符）的位置。
        p = strchr(p,'=')+1;
        sscanf(p,"%d",arr); 
        //C 库函数 int sscanf(const char *str, const char *format, ...) 从字符串读取格式化输入。
        printArray(arr,1);
        return 1;
    }
    p = strchr(p,'{')+1;
    printf("%s\n",p);
    int i = 0;
    while (*p != '\0')
    {
        char tmp[] = "";
        char *p1 = p;
        int n = 0;
        while(*p!=','&& *p!='\0'){
            n++;
            p++;
        }
        strncat(tmp,p1,n);
        // C 库函数 char *strncat(char *dest, const char *src, size_t n) 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
        sscanf(tmp,"%d",(arr+i));
        i++;
        if(*p == '\0'){
            break;
        }
        p++;
    }
    int arr_len = i;
    printArray(arr,arr_len);
    return arr_len;
}

int main()
{
    int A[50] = {0};
    int B[50] = {0};
    int R = 0;
    char str[210];
    char *p = str;
    scanf("%s", str);
    printf("%s\n", str);

    const char s[2] = "}";

    p = strtok(str, s);
    // C 库函数 char *strtok(char *str, const char *delim) 分解字符串 str 为一组字符串，delim 为分隔符。
    int len_A = getData(p,A);
    p = strtok(NULL, s);
    int len_B = getData(p,B);
    p = strtok(NULL, s);
    getData(p,&R);

    // A[i]<=B[j]
    // distance(A[i],B[j])<=R
    // print all (A[i],B[j])
    size_t noFind = 1;
    for (int i=0;i<len_A;i++){
        for(int j=0;j<len_B;j++){
            if(A[i]-B[j]>0){
                continue;
            }
            if(B[j]-A[i]<=R){
                printf("(%d,%d)",A[i],B[j]);
                noFind = 0;
                continue;             
            }
            if(noFind){
                printf("(%d,%d)",A[i],B[j]);                
            }
            break;
        }
    }

    system("pause");
    return 0;
}