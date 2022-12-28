#include<stdio.h>
#include<stdbool.h>
#define MAX 1005

int a[MAX], b[MAX];
//int a[MAX][MAX], b[MAX[MAX];

int n, i, j, k;

int Check()
{
	int d1 = 1, d2 = 1;
	for(i = 0; i < n; ++i)
	{
		if(a[i] != b[i])
		{
			d2 = 0;
			break;
		}
	}
	if(d2 != 0) return 1;
	
	for(i = 0; i < n; ++i)
	{
		if(a[i] != b[n - 1 - i])
		{
			d1 = 0;
			break;
		}
	}
	if(d1 != 0) return -1;
	
	
	
	return 0;
}

int main()
{
	//gia su 2 mang cung kick thuoc dau vao
	//int m; size mang con lai?
	//int n = sizeof(a)/sizeof(int); hoac sizeof(a[0);
	
	printf("Nhap kich thuoc mang: ");
	fflush(stdin);
	scanf("%d", &n);
	printf("\nNhap mang 1 (mang a): \n\n");
	
	//Input
	
	for(i = 0; i < n; ++i)
	{
		printf("a[%d] = ", i + 1);
		fflush(stdin);
		scanf("%d", &a[i]);
	}
	
	printf("\nNhap mang 2 (mang b): \n\n");
	for(i = 0; i < n; ++i)
	{
		printf("b[%d] = ", i + 1);
		fflush(stdin);
		scanf("%d", &b[i]);
	}
	
	printf("\nSo sanh 2 mang: %d", Check());
	return 0;
}
