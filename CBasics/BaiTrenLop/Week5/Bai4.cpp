#include<stdio.h>
#include<stdlib.h>

long long mult(int a, int b)
{	
	if(a == 1)
	{
		return b;
	}
	else if(a > 1) return(b + mult(a - 1, b));
	return 0;
}

int main()
{
	int a, b;
	printf("Enter a: ");
	fflush(stdin);
	scanf("%d", &a);
	printf("Enter b: ");
	fflush(stdin);
	scanf("%d", &b);
	printf("Result: %d", mult(a, b));
}
