#include <stdio.h>
int main()
{
int n, i, j, tong;
printf("\nEnter N= : ");
scanf("%d", &n);
for (i=2; i<=n; i++)
{
tong = 1;
for (j=2; j<=i/2; j++)
if (i%j == 0)
tong += j;
if (tong == i)
printf("\n%d", i);
}
}
