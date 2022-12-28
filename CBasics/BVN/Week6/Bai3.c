#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

//char s[MAX];

void reverse(char *s)
{
	int i = 0, j = strlen(s) - 1;
	char tmp;
	while(i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++; j--;
	}
}

void convert(int n, char *s, int p)
{
	if(n == 0) 
	{
		//printf("\np is: %d\n", p);
		s[p] = '\0';
		//s[p] = (n % 2) + '0';
		return;
	}
	else
	{
		s[p] = (n % 2) + '0';
		//printf("\ns[%d] = %c\n", p, s[p]);
		convert(n / 2, s, p + 1);
	}
}

int main()
{
	char sel;
	do
	{ 
		int n;
		printf("\nNhap n: ");
		fflush(stdin); scanf("%d", &n);
		char *s = (char *)malloc(MAX * sizeof(char));
		char *s1 = (char *)malloc(MAX * sizeof(char));
		convert(n, s, 0);
		//printf("\nstrlen(s) = %d\ns now is: %s\n", strlen(s), s);
		reverse(s);
		if(strlen(s) % 4 != 0)
		{
			int cnt = 1, i;
			while(strlen(s) > cnt * 4)
			{
				cnt++;
			}
			//printf("\ncnt is = %d\n", cnt);
			strcpy(s1, s);
			int move = cnt * 4 - strlen(s);
			//printf("\nmove is: %d\n", move);
			for(i = 0; i < cnt; ++i)
			{
				s[i] = '0';
			}
			strcpy(s + move, s1);
			printf("\nResult: %s\n", s);
		}
		else printf("\nResult: %s\n", s);
		free(s1);
		free(s);
		printf("\nDo you want to continue [y/n]: ");
        fflush(stdin);
        scanf("%c", &sel);
        while(sel != 'n' && sel != 'y')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin);
            scanf("%c", &sel);
        }
    } while (sel == 'y'); 
	return 0;
}
