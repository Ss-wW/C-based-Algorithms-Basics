#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 1;
    int j = 1;
    printf("print i++ gives %d\n", i++);
    printf("after i++, i = %d\n", i);
    printf("print ++ j gives %d\n", ++j);
    printf("after ++j, j = %d\n", j);

    printf("begin for(i++)\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", i);
    }
    printf("after for loop, i = %d\n", i);
    printf("begin for(++j)\n");
    for (int j = 0; j < 3; ++j)
    {
        printf("%d\n", j);
    }
    printf("after for loop, j = %d\n", j);
    system("pause");
    return 0;
}