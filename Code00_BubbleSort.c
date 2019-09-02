#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void myBubbleSort(int arr[], int len)
{
    if (arr == NULL || len < 2)
    {
        return;
    }
    for (int e = len - 1; e > 0; e--)
    {
        for (int i = 0; i < e; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr + i, arr + i + 1);
            }
        }
    }
    return;
}

int *generateRandomArray(int len)
{
    int *p = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i)
    {
        *(p + i) = rand() % 100;
    }
    return p;
}
int main()
{
    int len = 6;
    time_t t;
    srand((unsigned int)time(&t));
    int *arr = generateRandomArray(len);
    //int arr[len] = {66,23,30,1,47,3};
    printf("generate random array with length = %d\n", len);
    for (int i = 0; i < len; ++i)
    {
        printf("%-4d", *(arr + i));
    }
    printf("\n");
    myBubbleSort(arr, len);
    printf("after bubble sort\n");
    for (int i = 0; i < len; ++i)
    {
        printf("%-4d", *(arr + i));
    }
    printf("\n");
    system("pause");
    return 0;
}


/* rand() 和 srand() 使用的库文件是 stdlib.h
rand() 函数返回一个范围在 0 到 RAND_MAX 之间的整数值。
RAND_MAX 是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 32767。
通过取模可以得到指定范围的随机整数.
rand()%Range 可以产生0~Range-1 的随机整数.
为了使每次程序运行时生成不同的随机数，需要用 srand( ) 初始化随机种子.
#include <time.h>
time_t t;
srand((unsigned)time(&t));

下面是 srand() 函数的声明。
void srand(unsigned int seed) //播种由函数 rand 使用的随机数发生器。
seed -- 这是一个整型值，用于伪随机数生成算法播种。
该函数不返回任何值。
rand() 函数的声明。
int rand(void) */