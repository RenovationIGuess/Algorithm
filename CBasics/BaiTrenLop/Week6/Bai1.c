#include<stdio.h>
#include<stdlib.h>

int recursion(int n)
{
    if(n == 1) return 1;
    return recursion(n - 1) + n;
}

int main()
{
    int n;
    printf("\nHay nhap n: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\nSum (1 -> n): %d.", recursion(n));
    return 0;
}
