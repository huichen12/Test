/* Fibonacci数列的非递归实现*/
/*
样例输入 Copy
40
样例输出 Copy
102334155
*/
#include<stdio.h>
#include<string.h>

int a[1001][501];

void fun()
{
    int i, j, k;
    memset(a, 0, sizeof(a));
    a[1][0] = 1;
    a[2][0] = 1;
    for (i = 3; i <= 1000; i++)
    {
        k = 0;
        for (j = 0; j <= 500; j++)
        {
            a[i][j] = a[i - 1][j] + a[i - 2][j] + k;
            k = a[i][j] / 10;
            a[i][j] = a[i][j] % 10;
        }
    }
}
int main()
{
    fun();
    int n, i, j;
    int b;
    scanf("%d", &b);
    for (i = 500; i >= 0; i--)
    {
        if (a[b][i] != 0)
            break;
    }
    for (j = i; j >= 0; j--)
        printf("%d", a[b][j]);

    return 0;
}

