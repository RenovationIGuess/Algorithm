#include<stdio.h>
#include<stdlib.h>

int C(int k, int n)
{
	if(k == 0 || k == n)
		return 1;
	int C1 = C(k - 1, n - 1);
	int C2 = C(k, n - 1);
	return C1 + C2;
}

int main()
{
	int n, k;
	printf("Enter n: ");
	fflush(stdin);
	scanf("%d", &n);
	printf("Enter k: ");
	fflush(stdin);
	scanf("%d", &k);
	printf("Result: %d", C(k, n));
}
