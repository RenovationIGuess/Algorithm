#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

int m[MAX][MAX];

int C(int k, int n)
{
    if(k == 0 || k == n)
    {
        m[k][n] = 1;
    }
    else
    {
        if(m[k][n] < 0)
        {
            m[k][n] = C(k - 1, n - 1) + C(k, n - 1);
        }
    }
    return m[k][n];
}

int main()
{
    int n;
    printf("Nhap n: ");
    fflush(stdin);
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n + 1; ++i)
    {
        for(j = 0; j < n + 1; ++j)
        {
            m[i][j] = -1;
        }
    }
    printf("%d\n", C(n / 2, n));
}