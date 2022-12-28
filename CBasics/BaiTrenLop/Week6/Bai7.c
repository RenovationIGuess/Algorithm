#include<stdio.h>

int n, k;
int a[101];

void Try(int p)
{
    int i;
    for(i = a[p - 1] + 1; i <= n - k + p; ++i)
    {
        a[p] = i;
        if(p == k)
        {
            int j;
            for(j = 1; j <= k; ++j)
                printf("%d", a[j]);
            printf("\n");
        }
        else Try(p + 1);
    }
}

int main()
{
    printf("Nhap n: "); scanf("%d", &n);
    printf("Nhap k: "); scanf("%d", &k);
    Try(1);
    return 0;
}