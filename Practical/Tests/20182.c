#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

typedef struct
{
	int phan_nguyen;
	int tu_so;
	int mau_so;
} PS;

PS PhanSo[100];

void Func1()
{
	int a[101][101];
	int n;
	printf("Nhap So Nguyen Khong Am: ");
	fflush(stdin);
	scanf("%d", &n);
	printf("Nhap Ma Tran: \n");
	int i, j;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			printf("[%d][%d] = ", i, j);
			fflush(stdin);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nMa Tran Da Nhap: \n\n");
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j < n; ++j)
			printf("%d ", a[i][j]);
		printf("%d\n", a[i][n]);
	}
		
	int check = 1;
	/*
	for(i = 1; i < n; ++i)
	{
		for(j = i + 1; j <= n; ++j)
		{
			if(a[i][j] != 0 || a[j][i] != 0)
			{
				check = 0;
				break;
			}
			if(a[i][i] != 1) 
			{
				check = 0;
				break;
			}
 		}
 		if(check == 0) break;
	}
	*/
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			if(i == j && a[i][j] != 1)
			{
				check = 0;
				break;	
			} 
			if(i != j && a[i][j] != 0) 
			{
				check = 0;
				break;
			}
		}
		if(check == 0) break;
	}
	if(check) printf("\nCo\n");
	else printf("\nKhong\n");
}

void Fix(char s[])
{
	int i;
	while(s[0] == ' ') strcpy(&s[0], &s[1]);
	for(i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ' ' && s[i + 1] == ',')
		{
			strcpy(&s[i], &s[i + 1]);
			i--;
		} 
		else if(s[i] == ' ' && s[i + 1] == ' ')
		{
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	while(s[strlen(s) - 1] == ' ') strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
}

void Func2()
{
	int n; //num
	//int check = 0;
	char c, kt; //char
	
	/*printf("Nhap So n: "); 
	fflush(stdin);
	scanf("%d", &n);
	printf("Nhap Chieu Tam Giac: ");
	fflush(stdin);
	scanf("%c", &c); */
	
	char s[100];
	printf("Nhap Input: ");
	fflush(stdin);
	gets(s);
	Fix(s);
		if(s[0] >= 'A' && s[0] <= 'Z') 
		{
			c = s[0];
			int i;
			int p = 0; //position
			int m = 0; //mu 
			n = 0;
			for(i = strlen(s) - 1; i >= 0; --i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = strlen(s) - 1; i >= p + 2; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
		else if(s[strlen(s) - 1] >= 'A' && s[strlen(s) - 1] <= 'Z') 
		{
			c = s[strlen(s) - 1];
			int i;
			int p = 0; //position
			int m = 0; //mu 
			n = 0;
			for(i = 0; i <= strlen(s) - 1; ++i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = p - 1; i >= 0; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
	while(c != 'X' && c != 'N' || kt != ',')
	{
		printf("Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		gets(s);
		Fix(s);
		if(s[0] >= 'A' && s[0] <= 'Z') 
		{
			c = s[0];
			int i;
			int p = 0; //position
			int m = 0; //mu
			n = 0; 
			for(i = strlen(s) - 1; i >= 0; --i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = strlen(s) - 1; i >= p + 2; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
		else if(s[strlen(s) - 1] >= 'A' && s[strlen(s) - 1] <= 'Z') 
		{
			c = s[strlen(s) - 1];
			int i;
			int p = 0; //position
			int m = 0; //mu 
			n = 0;
			for(i = 0; i <= strlen(s) - 1; ++i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = p - 1; i >= 0; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
		//check++;
	} 
	/*if(check != 0)
	{
		if(s[0] >= 'A' && s[0] <= 'Z') 
		{
			c = s[0];
			int i;
			int p = 0; //position
			int m = 0; //mu
			n = 0; 
			for(i = strlen(s) - 1; i >= 0; --i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = strlen(s) - 1; i >= p + 2; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
		else if(s[strlen(s) - 1] >= 'A' && s[strlen(s) - 1] <= 'Z') 
		{
			c = s[strlen(s) - 1];
			int i;
			int p = 0; //position
			int m = 0; //mu 
			n = 0;
			for(i = 0; i <= strlen(s) - 1; ++i)
			{
				if(s[i] == ',')
				{
					p = i;
					break;
				}
			}
			for(i = p - 1; i >= 0; --i)
			{
				n += (int)(s[i] - '0') * pow(10, m); 
				m++;
			}
			kt = s[p];
		}
	} */
	int i, j;
	printf("\n");
	if(c == 'X')
	{
		int tmp = n;
		for(i = 1; i <= n; ++i)
		{
			if(i != n)
			{
				for(j = 1; j <= tmp - 1; ++j)
					printf(" ");
			}
			j = 2*i - 1;
			while(j >= 1)
			{
				printf("*");
				j--;
			}
			tmp--;
			printf("\n");
		}
	}
	if(c == 'N')
	{
		int tmp = 0;
		for(i = n; i >= 1; --i)
		{
			if(i != n)
			{
				for(j = 1; j <= tmp; ++j)
					printf(" ");
			}
			j = 2*i - 1;
			while(j >= 1)
			{
				printf("*");
				j--;
			}
			tmp++;
			printf("\n");
		}
	}
}

void Func3()
{
	char s[100]; //so dien thoai
	printf("\nNhap Vao So Dien Thoai: ");
	fflush(stdin);
	gets(s);
	int i;
	while(strlen(s) == 10 && s[0] == '0' || strlen(s) < 10) 
	{
		printf("Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		gets(s);
	}
	if(strlen(s) == 10) printf("So Dien Thoai Sau Chuyen: %s\n", s);
	if(strlen(s) == 11)
	{
		while(s[0] == '0' && strlen(s) > 10)
		{
			for(i = 1; i <= strlen(s); ++i)
			{
				s[i - 1] = s[i];
			}
		}
		if(strlen(s) == 10)
		{
			printf("So Dien Thoai Sau Chuyen: %s", s);
			return;
		}
		if(s[0] == '1' && s[1] == '6' && s[3] >= '2' && s[3] <= '9')
		{
			for(i = 1; i <= strlen(s); ++i)
			{
				s[i - 1] = s[i];
			}
			s[0] = '3';
			printf("So Dien Thoai Sau Chuyen: %s\n", s);
		} 
		else printf("Khac Nha Mang!\n");
	}
	if(strlen(s) > 11)
	{
		char tmp[100];
		for(i = 0; i < 11; ++i)
		{
			tmp[i] = s[i];
		}
		while(tmp[0] == '0' && strlen(tmp) > 10)
		{
			for(i = 1; i <= strlen(tmp); ++i)
			{
				tmp[i - 1] = tmp[i];
			}
		}
		if(strlen(tmp) == 10) 
		{
			printf("So Dien Thoai Sau Chuyen: %s\n", tmp);
			return; 
		}
		if(tmp[0] == '1' && tmp[1] == '6' && tmp[3] >= '2' && tmp[3] <= '9')
		{
			for(i = 1; i <= strlen(tmp); ++i)
			{
				tmp[i - 1] = tmp[i];
			}
			tmp[0] = '3';
			printf("So Dien Thoai Sau Chuyen: %s\n", tmp);
		} 
		else printf("Khac Nha Mang!\n");
	}
}

int findUCLN(int a, int b) {
	if(b == 0) return a;
	return findUCLN(b, a % b);
}
void simplify(int *a, int *b) {
	int u = findUCLN(*a, *b);
	*a /= u;
	*b /= u;
}

bool KiemTra()
{
	int i;
	for(i = 1; i <= 2; ++i)
	{
		if(PhanSo[i].tu_so > PhanSo[i].mau_so)
			return false;
	}
	return true;
}

void Input4(PS *p)
{
	/*printf("Nhap Phan Nguyen: ");
	fflush(stdin); 
	scanf("%d", &p->phan_nguyen);
	printf("Nhap Tu So: ");
	fflush(stdin);
	scanf("%d", &p->tu_so);
	printf("Nhap Mau So: ");
	fflush(stdin);
	scanf("%d", &p->mau_so); */
	char slash;
	scanf("%d %d%c%d", &p->phan_nguyen, &p->tu_so, &slash, &p->mau_so);
	while(slash != '/')
	{
		printf("Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		scanf("%c", &slash);
	}
	while(p->mau_so == 0 || !KiemTra())
	{
		printf("Invalid! Nhap Lai: ");
		fflush(stdin);
		scanf("%d %d%c%d", &p->phan_nguyen, &p->tu_so, &slash, &p->mau_so);
	}
	//simplify(&p->tu_so, &p->mau_so);
}

void Func4()
{
	int i;
	for(i = 1; i <= 2; ++i)
	{
		printf("Nhap Hon So %d: ", i);
		Input4(&PhanSo[i]);
	}
	for(i = 1; i <= 2; ++i)
	{
		if(PhanSo[i].tu_so == 0) 
		{
			printf("\nInvalid\n");
			return;
		}
		/*if(PhanSo[i].tu_so > PhanSo[i].mau_so)
		{
			printf("\nInvalid\n");
			return;
		} */
	}
	for(i = 1; i <= 2; ++i)
		PhanSo[i].tu_so = PhanSo[i].phan_nguyen * PhanSo[i].mau_so + PhanSo[i].tu_so;
	int Tu = PhanSo[1].tu_so * PhanSo[2].mau_so;
	int Mau = PhanSo[1].mau_so * PhanSo[2].tu_so;
	if(Tu / Mau > 1) 
	{
		int PN = (int)(Tu / Mau);
		Tu = Tu - PN * Mau;
		simplify(&Tu, &Mau);
		printf("\nKet Qua: %d %d/%d\n", PN, Tu, Mau);
	} 
	else 
	{
		simplify(&Tu, &Mau);
		printf("\nKet Qua: %d/%d\n", Tu, Mau);
	}
}

void Menu()
{
	int func;
	printf("Chuong Trinh 2018: ");
	do 
	{
		printf("\n1. Ma Tran.\n2. Tam Giac.\n3. Chuyen So.\n4. Phan So.\n5. Exit.\n");
		printf("Nhap Chuc Nang: ");
		fflush(stdin);
		scanf("%d", &func);
		while(func < 1 || func > 5)
		{
			printf("Khong Hop Le! Nhap Lai: ");
			fflush(stdin);
			scanf("%d", &func);
		}
		switch(func)
		{
			case 1: 
				Func1();
				break;
			case 2: 
				Func2();
				break;
			case 3: 
				Func3();
				break;
			case 4:
				Func4();
				break;
			case 5:
				printf("\nCam On Vi Da Su Dung!\n");
				break;
		}
	} while(func != 5);
}

int main()
{
	Menu();
	return 0;
}
