#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int res;

//dem so cach chon
long Try1(int n, int k)
{
	long r;
	if(k == 1)
	{
		return n;
	}
	if(k == 2 * n - 1)
	{
		return 1;
	}
	r = Try1(n - 1, k) + Try1(n - 2, k - 1);
	return r;
}


// In ra cu the nhung n bi gioi han
//void Try(int *a, int *check, int n, int k, int p)
void Try(int *a, int n, int k, int p)
{
	int i, j;
	for(i = a[p - 1] + 1; i <= n - k + p; ++i)
	{
		if(p > 1 && a[p - 1] + 1 == i)
		{
			continue;
		}
		//if(!check[i] && a[p + 1] != i + 1)
		//if(!check[i])
		//{
			a[p] = i;
			//check[i] = 1;
			if(p == k)
			{
				res++;
				printf("\nCach %d:\n", res);
				for(j = 1; j <= k; ++j)
				{
					printf("%d ", a[j]);
				}
				printf("\n");
			}
			//else Try(a, check, n, k, p + 1);
			else Try(a, n, k, p + 1);
			//check[i] = 0;
		//}
	}
}

int main()
{
	char sel;
        do
        {
            int n, k;
			printf("\nHay nhap n: ");
			fflush(stdin); scanf("%d", &n);
			while(n <= 0) 
			{
				printf("\nKhong hop le! Nhap lai: ");
				fflush(stdin); scanf("%d", &n);
			}
			printf("\nHay nhap k: ");
			fflush(stdin); scanf("%d", &k);
			if(n % 2 != 0)
			{
				while(k <= 0 || k > n / 2 + 1)
				{
					printf("\nKhong hop le (khong ton tai cach chon)!\nNhap lai: ");
					fflush(stdin); scanf("%d", &k);
				}
			}
			else
			{
				while(k <= 0 || k > n / 2)
				{
					printf("\nKhong hop le! Nhap lai: ");
					fflush(stdin); scanf("%d", &k);
				}
			}
			int *a = (int *)malloc((k + 5) * sizeof(int));
			//int *check = (int *)malloc((n + 5) * sizeof(int));
			//memset(check, 0, sizeof(int) * (n + 5));
			//check = {0};
			a[0] = 0;
			int i;
			res = 0;
			//Try(a, check, n, k, 1);
			Try(a, n, k, 1);

			//res = Try1(n, k); 

			printf("\nVay co tong %d cach chon.\n", res);
			//else 
				//printf("\nKhong ton tai cach nao!\n");
			//free(check);
			free(a);
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
