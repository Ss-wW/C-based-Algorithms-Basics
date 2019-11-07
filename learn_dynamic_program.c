// question: get 15 with minimum number of 1, 5 or 11;
// 还有问题，只能输出最少钱币数，但还不能输出具体的钞票方案
#include <stdio.h>
#include <stdlib.h>

#define min(x, y) x < y ? x : y

int main()
{
    int n; // scnaf to get the object number
    printf("%s\n", "How much is the product?");
    n = 15;//scanf("%d", &n);
    //n++;
    int f[n]; // f[n] is the cost to get n, f(n) = min{f(n-1),f(n-4),f(n-11)} + 1
    f[0] = 0;
    int m;
    printf("%s\n", "How many kinds of cash do you have?");
    m = 3;//scanf("%d", &m);
    int cash[m];
    int cash_count[n][m] = {0,0,0};
    int i = 0;
    int count = 0;
    printf("%s\n", "input the different values of your cash");
    cash[0] = 1;
    cash[1] = 5;
    cash[2] = 11;
    // while (scanf("%d", cash + i++) && count < m - 1)
    // {
    //     count++;
    // }
    // cash need to be sorteded to be left least sequence
    int cost;
    for (int i = 1; i <= n; i++)
    {
        cost = __INT_MAX__;
        // begin with i=1
        for (int j = 0; j < m; j++)
        {
            if (i >= cash[j])
            {
                cost = min(cost, f[i - cash[j]]) + 1; // if i=5,6,7,8,9,10
                if (i % cash[j] == 0 && j > 0)
                {
                    cash_count[i-1][j - 1] = cash_count[i-1][j - 1] - cash[j];
                }
                cash_count[i-1][j]++;
            }
        }
        f[i] = cost;
    }
    printf("You need to use at least %d cash\n", f[n]);

    for (int i = 0; i < m; i++)
    {
        printf("%d$: %d\n", cash[i], cash_count[n-1][i]);
    }

    printf("\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("f[%d] = %d\t", i, f[i]);
        for (int j = 0; j < m; j++)
        {
            printf("%d$: %d\t", cash[j], cash_count[i-1][j]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
    return 0;
}
