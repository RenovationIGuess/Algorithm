#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define square(x) x*x
#include<conio.h>
struct T
{
	char Ten[20];
	unsigned NS;
} t, *p, a[10];

int swap(int a, int b)
{
	int tmp = a;
	a = b; 
	b = tmp;
	return 0;
}

int reverse(int n)
{
	if(n == 0)
		return 0;
	else 
		printf("%d", n);
	reverse(n - 1);
}

void f(int a[])
{
	int i;
	for(i = 0; i < 3; ++i)
	{
		a[i]++;
	}
}

void print(int a[])
{
	for(int i = 0; i < 3; ++i)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int x = 1;
	do
		printf("%d ", x);
	while(x++ <= 1);
	return 0;
}
