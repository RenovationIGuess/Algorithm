#include<stdio.h>

int n;
int a[101];
int check[101] = {0};

void Try(int p)
{
    int i, j;
    for(i = 0; i <= 1; ++i)
    {
        if(a[p - 1] + i < 2)
        {
            a[p] = i;
        }
        if(p == n)
        {
            for(j = 1; j <= n; ++j)
            {
                printf("%d", a[j]);
            } printf("\n");
        }
        else Try(p + 1);
    }
}

int main()
{
    printf("Nhap n: ");
    scanf("%d", &n);
    a[0] = 0;
    Try(1);
    return 0;
}