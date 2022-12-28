#include<stdio.h>
#include<stdlib.h>

int noOfDigits(int n)
{
	static int ctr = 0;
	if(n != 0)
	{
		ctr++;
		noOfDigits(n / 10);
	}
	return ctr;
}

int DigitSum(int n)
{
	if(n == 0)
		return 0;
	return((n % 10) + DigitSum(n / 10));
}

int main()
{
	int n;
	printf("Enter n: ");
	fflush(stdin);
	scanf("%d", &n);
	printf("Result:\nNumber of digits: %d\nSum of digits: %d", noOfDigits(n), DigitSum(n));
	return 0;
}
