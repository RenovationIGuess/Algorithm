#include<stdio.h>
#include<stdlib.h>

int triangle1(int n)
{
	int total = 0;
	while(n > 0)
	{
		total += n;
		--n;
	}
	return total;
}

int triangle(int n)
{
	if(n == 1)
	{
		//printf("%d ", n);
		return 1;
	}
	else
		//printf("%d ", n);
		return(n + triangle(n - 1));
}

int main()
{
	int n;
	printf("Enter n: ");
	fflush(stdin);
	scanf("%d", &n);
	//triangle(n);
	int i;
	for(i = 1; i <= n; ++i)
	{
		printf("%d ", triangle(i));
	}
	return 0;
}
