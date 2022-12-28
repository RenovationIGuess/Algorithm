#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

int main()
{
	srand((int)time(0));
	int n;
	scanf("%d", &n);
	char s[50][50];
	int i;
	for(i = 0; i < n; ++i)
	{
		fflush(stdin);
		gets(s[i]);
	}
	
	for(i = 0; i < n*n; ++i)
	{
		printf("%s %s\n", s[random(0, n - 1)], s[random(0, n - 1)]);
	}
}
