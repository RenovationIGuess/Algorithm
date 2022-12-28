#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	fflush(stdin);
	gets(s);
	printf("%d", strlen(s));
	return 0;
}
