#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct {
	char TenSV[20];
	float DiemQT, DiemCK, DiemTK;
	char DiemXL;
} DiemSV;

int n, cnt = 0; //so sinh vien va ktra nhap 1 chua
DiemSV BangDiem[42];

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);

void InputSV(DiemSV *p)
{
	printf("Ten SV: ");
	fflush(stdin);
	gets(p->TenSV);
	//chuan hoa
	fix(p->TenSV);
	printf("Diem QT: ");
	fflush(stdin);
	scanf("%f", &p->DiemQT);
	while(p->DiemQT < 0 || p->DiemQT > 10)
	{
		printf("Diem Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		scanf("%f", &p->DiemQT);
	}
	printf("Diem CK: ");
	fflush(stdin);
	scanf("%f", &p->DiemCK);
	while(p->DiemCK < 0 || p->DiemCK > 10)
	{
		printf("Diem Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		scanf("%f", &p->DiemCK);
	}
	//do while	
	p->DiemTK = 0.4 * p->DiemQT + 0.6 * p->DiemCK;
	if(p->DiemTK >= 8.5) p->DiemXL = 'A';
	if(p->DiemTK >= 7 && p->DiemTK < 8.5) p->DiemXL = 'B';
	if(p->DiemTK < 7 && p->DiemTK >= 5.5) p->DiemXL = 'C';
	if(p->DiemTK < 5.5 && p->DiemTK >= 4) p->DiemXL = 'D';
	if(p->DiemTK < 4) p->DiemXL = 'F';
	//else if
}

void Func1()
{
	if(cnt == 0)
	{
		printf("Nhap So Sinh Vien: "); scanf("%d", &n);
		while(n < 0 || n > 40)
		{
			printf("So Sinh Vien Phai Nam Trong [1, 40]\nHay Nhap Lai: ");
			fflush(stdin);
			scanf("%d", &n);
		}
		int i;
		for(i = 1; i <= n; ++i)
		{
			printf("\nNhap Thong Tin Sinh Vien Thu %d: \n", i);
			InputSV(&BangDiem[i]);
		}
	}
	else
	{
		int e; //extra
		printf("Nhap So Sinh Vien Muon Them: ");
		fflush(stdin);
		scanf("%d", &e);
		n += e;
		while(n > 40)
		{
			printf("Qua So Luong Cho Phep! Nhap Lai: ");
			fflush(stdin);
			scanf("%d", &e);
		}
		int i;
		for(i = n - e + 1; i <= n; ++i)
		{
			printf("\nNhap Thong Tin Sinh Vien Thu %d: \n", i);
			InputSV(&BangDiem[i]);
		}
	}
}

void Func2()
{
	printf("\n%-23s%-10s%-10s%-10s%-10s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep Loai");
	int i;
	for(i = 1; i <= n; ++i)
	{
		printf("%-23s%-10.1f%-10.1f%-10.1f%-10c\n", BangDiem[i].TenSV, BangDiem[i].DiemQT,
		BangDiem[i].DiemCK, BangDiem[i].DiemTK, BangDiem[i].DiemXL);
	}
}

void Func3()
{
	int L;
	printf("Nhap Vao So Nguyen L: ");
	fflush(stdin); 
	scanf("%d", &L);
	while(L < 2 || L > 5) 
	{
		printf("Khong Hop Le! Nhap Lai: ");
		fflush(stdin);
		scanf("%d", &L);
	}
	int ok[45] = {0};
	bool check = false;
	int i;
	for(i = 1; i <= n; ++i)
	{
		float res = BangDiem[i].DiemCK - BangDiem[i].DiemQT;
		if(res < 0) res = -res;
		if(res >= L) 
		{
			check = true;
			ok[i] = 1;
		}
	}
	if(check == true)
	{
		printf("\n%-23s%-10s%-10s%-10s%-10s\n", "Ten SV", "Diem QT", "Diem CK", "Diem TK", "Xep Loai");
		for(i = 1; i <= n; ++i)
		{
			if(ok[i] == 1)
			{
				printf("%-23s%-10.1f%-10.1f%-10.1f%-10c\n", BangDiem[i].TenSV, BangDiem[i].DiemQT,
				BangDiem[i].DiemCK, BangDiem[i].DiemTK, BangDiem[i].DiemXL);
			}
		}
	} else printf("\nKhong Ton Tai Hoc Sinh Thoa Man!\n");
}

void Func4()
{
	int i, j;
	char Ten[45][21];
	for(i = 1; i <= n; ++i)
	{
		for(j = strlen(BangDiem[i].TenSV) - 1; j >= 0; --j)
		{
			if(BangDiem[i].TenSV[j] == ' ')
			{
				int k, h = 0;
				for(k = j + 1; k <= strlen(BangDiem[i].TenSV); ++k)
				{
					Ten[i][h] = BangDiem[i].TenSV[k];
					h++;
				}
				break;
			}
		}
	}
	char Name[21];
	for(i = 1; i < n; ++i)
	{
		for(j = i + 1; j <= n; ++j)
		{
			if(BangDiem[i].DiemTK < BangDiem[j].DiemTK)
			{
				DiemSV tmp = BangDiem[i];
				BangDiem[i] = BangDiem[j];
				BangDiem[j] = tmp;
				strcpy(Name, Ten[i]);
				strcpy(Ten[i], Ten[j]);
				strcpy(Ten[j], Name);
			}
			else if(BangDiem[i].DiemTK == BangDiem[j].DiemTK)
			{
				if(strcmp(Ten[i], Ten[j]) > 0)
				{
					DiemSV tmp = BangDiem[i];
					BangDiem[i] = BangDiem[j];
					BangDiem[j] = tmp;
					strcpy(Name, Ten[i]);
					strcpy(Ten[i], Ten[j]);
					strcpy(Ten[j], Name);
				}
			}
		}
	}
	Func2();
}

void menu()
{
	int s; //services
	printf("Chuong Trinh Quan Ly Diem Mon Hoc\n");
	printf("1. Nhap Diem\n2. In Bang Diem\n3. Chenh Lenh Diem\n4.Sap Xep\n5.Thoat Chuong Trinh\n");
	do 
	{
		printf("Press (1, 2, 3, 4, 5) to choose: ");
		fflush(stdin);
		scanf("%d", &s);
		while(s < 1 || s > 5)
		{
			printf("Invalid Number! Try again: ");
			fflush(stdin);
			scanf("%d", &s);
		}
		switch(s)
		{
			case 1: 
				Func1();
				cnt++;
				break;
			case 2:
				if(cnt == 0) 
				{
					printf("\nNhap Thong Tin Truoc!\n");
					break;
				}
				Func2();
				break;
			case 3:
				if(cnt == 0) 
				{
					printf("\nNhap Thong Tin Truoc!\n");
					break;
				}
				Func3();
				break;
			case 4: 
				if(cnt == 0) 
				{
					printf("\nNhap Thong Tin Truoc!\n");
					break;
				}
				Func4();
				break;
			case 5: 
				printf("\nCam On Vi Da Su Dung!\n");
				//exit(0);
				break;
		}
	} while(s != 5);
}

int main()
{
	menu();
	return 0;
}

bool isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; 
	//true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void fix(char s[]) {
	//xoa dau
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	
	//xoa giua
	for(int i = 0; i < strlen(s); ++i) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	
	//cho an toan :v
	//chuyen thanh ' '
	for(int i = 0; i < strlen(s); ++i)
	{
		if(isWhite(s[i]) || speC(s[i]) && s[i] != ' ')
			s[i] = ' ';
	} 
	 
	//xoa cuoi
	while(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
	
	//in hoa ky tu dau
	if(!isupper(s[0])) s[0] -= 32;
	for(int i = 1; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
			if(!isupper(s[i + 1]))
				s[i + 1] -= 32;
	}
}

