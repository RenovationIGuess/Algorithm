#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	/*char s[100];
	fflush(stdin);
	gets(s); 
	int i;
	for(i = 1; i <= strlen(s); ++i)
	{
		s[i - 1] = s[i];
	}
	s[0] = '3';
	printf("%s, %d", s, strlen(s)); 
	int i;
	while(s[0] == ' ') strcpy(&s[0], &s[1]);
	for(i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ' ' && s[i + 1] == ',')
		{
			strcpy(&s[i], &s[i + 1]);
			//i--;
		} 
		if(s[i] == ' ' && s[i + 1] == ' ')
		{
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	while(s[strlen(s) - 1] == ' ') strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	printf("\"%s\"%-10s", s); */
	int a, cnt = 0;
	scanf("%d", &a);
	int tmp = a;
	while(tmp > 0)
	{
		tmp /= 10;
		cnt++;
	}
	//printf("%d\n", 101 % 100);
	char d = 101 % 100 + '0';
	//printf("%c\n", d);
	char c[100];
	c[0] = '(';
	int i = 1;
	int k = i + cnt - 1;
	int tmp1 = k;
	while(cnt > 1)
	{
		int tmp3 = cnt, tmp4 = 1;
		while(tmp3 > 1)
		{
			tmp4 *= 10;
			tmp3--;	
		}
		//printf("%d\n", tmp4);
		//printf("%d\n", a % tmp4);
		c[k] = a % tmp4 + '0';
		printf("%c %d\n", c[k], k);
		//printf("%c\n", c[k]);
		a /= 10;
		cnt--;
		k--;
	} 
	//printf("%d\n", a);
	c[i] = a + '0';
	printf("%c %d\n", c[i], i);
	i = tmp1;
	i++;
	c[i] = ')';
	printf("%c %d\n", c[i], i);
	printf("%s", c);
	return 0;
}
