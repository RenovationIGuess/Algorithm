#include<stdio.h>
#include<string.h>
#define MAX 101
#define mlen 50
#define mlen1 30

typedef struct 
{
	char fname[mlen];
	char name[mlen1];
} stu;

stu st[MAX];
int visit[MAX] = {0};
int n, i, j, k;

void print()
{
	for(i = 0; i < n; ++i)
	{
		printf("%s\n", st[i].fname);
	}
}

void Sort()
{
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(st[i].name[0] > st[j].name[0])
			{
				stu tmp;
				tmp = st[i];
				st[i] = st[j];
				st[j] = tmp;
			} 
		}
	}
}

/*int check(int u, char s[])
{
	if(u == 0) return 0;
	for(i = 0; i < u; ++i)
	{
		if(strcmp(st[i].name, s) == 0) return 1;
		//da xuat hien
	}
	return 0;
	//chua xuat hien
}*/

int MaxNum()
{
	int Max = -1;
	for(i = 0; i < n; ++i)
	{
		if(visit[i] == 0)
		{
			int cnt = 1;
			for(j = i + 1; j < n; ++j)
			{
				if(strcmp(st[i].name, st[j].name) == 0) 
				{
					cnt++;
					visit[j] = 1;
				} 
			}
			if(cnt > Max) Max = cnt;
		}
		//if(check(i, st[i].name) == 1) continue;
	}
	return Max;
}

int main()
{	
	printf("Hay nhap so hoc sinh: ");
	fflush(stdin);
	scanf("%d", &n);
	printf("\n");
	
	for(i = 0; i < n; ++i)
	{
		printf("Hay nhap ten hoc sinh thu %d: ", i + 1);
		fflush(stdin);
		gets(st[i].fname);
		printf("\n");
		for(j = strlen(st[i].fname) - 1; j >= 0 ; --j)
		{
			if(st[i].fname[j] == ' ') 
			{
				int h = 0;
				for(k = j + 1; k <= strlen(st[i].fname); ++k)
				{
					st[i].name[h] = st[i].fname[k];
					h++;
				}
				break;
			}
		}
	}
	
	Sort();
	printf("\nDanh sach sinh vien: \n\n");
	print();
	printf("\n");
	
	printf("Ten sv xuat hien nhieu nhat: %d\n", MaxNum());
	
	/*for(i = 0; i < n; ++i)
	{
		printf("%s\n", st[i].name);
	} */
	return 0;
}
