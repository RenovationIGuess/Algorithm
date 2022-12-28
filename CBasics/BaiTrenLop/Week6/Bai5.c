#include<stdio.h>

int n;
int a[51];

void Try(int k)
{
    int i;
    for(i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if(k == n)
        {
            int j;
            for(j = 1; j <= n; ++j)
            {
                printf("%d", a[j]);
            } printf("\n");
        }
        else Try(k + 1);
    }
}

int main()
{
    printf("Nhap n: ");
    scanf("%d", &n);
    Try(1);
    return 0;
}