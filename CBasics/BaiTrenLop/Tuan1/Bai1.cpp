#include<stdio.h>
#define oo 1000
#define SIZE 100

int main()
{
	int i;
	float A[SIZE];
	
	int n;
	scanf("%d", &n);
	
	//float *ptr = (float*)malloc(n * sizeof(float));
	float tb = 0;
	
	printf("Enter 10 numbers: \n");
	for(i = 0; i < n; ++i)
	{
		scanf("%f", &A[i]);
		tb += A[i];
	}
	
	tb = tb/10;
	
	float ss = oo;
	int p = 0;
	
	for(i = 0; i < 10; ++i)
	{
		float ans = tb - A[i];
		if(ans < 0) ans = -ans;
		if(ss > ans) 
		{
			ss = ans;
			p = i;
		}
	}
	
	printf("%-20s%-20s%-20s\n", "Gia tri trung binh", "So gan nhat", "Sai so");
	printf("%-20.4f%-20.4f%-20.4f\n", tb, A[p], ss);
	
	/*printf("Gia tri trung binh: %3.4f\n", tb);
	printf("So gan nhat la: %3.4f\n", A[p]);
	printf("Sai so la: %3.4f\n", ss); */
	
	//free(ptr);
	return 0;
}
