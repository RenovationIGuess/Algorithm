#include<stdio.h>

int x[101];
int n;

int check(int v, int k)
{
    int i;
    for(i = 1; i <= k - 1; ++i)
    {
        if(x[i] == v) return 0;
        if(x[i] + i == v + k) return 0;
        if(x[i] - i == v - k) return 0;
    }
    return 1;
}

void print()
{
    int i;
    for(i = 1; i <= n; ++i)
    {
        printf("%d", x[i]);
    }
}

void Try(int k)
{
    int i;
    for(i = 1; i <= n; ++i)
    {
        if(check(i, k))
        {
            x[k] = i;
            if(k == n) print();
            else Try(k + 1);
        }
    }
}

int main()
{
    //int n;
    x[0] = 0;
    printf("Nhap size ban co: ");
    scanf("%d", &n);
    Try(1);
    return 0;
}