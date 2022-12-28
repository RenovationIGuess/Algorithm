#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 25

//Em dung DevC thay chay = DevC giup em neu duoc a
//Nguyen Tung Lam 20204998

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);

typedef struct 
{
	int id;
	char nation[5];
	char name[35];
	float R[5];
	float ketqua;
} olympic;

int n; //so van dong vien
olympic vdv[MAX];
int cnt1 = 0, cnt2 = 0;

char *strcasestr(const char *str, const char *pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper((unsigned char)*str) == toupper((unsigned char)*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper((unsigned char)str[i]) != toupper((unsigned char)pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}

int kiemtraid(int u, int v)
{
	int i;
	if(u == 1) return 1;
	//u la vi tri trong mang, v la gia tri id
	for(i = 1; i < u; ++i)
	{
		if(vdv[i].id == v)
			return 0;
	}	
	return 1;
}

void getInf(olympic *ps, int u)
{
	printf("Nhap ID: ");
	fflush(stdin);
	scanf("%d", &ps->id);
	while(ps->id < 0 || !kiemtraid(u, ps->id))
	{
		printf("ID khong hop le! Hay nhap lai: ");
		fflush(stdin);
		scanf("%d", &ps->id);
	}
	
	printf("Nhap Nation: ");
	fflush(stdin);
	gets(ps->nation);
	while(strlen(ps->nation) > 3)
	{
		printf("Khong hop le! Hay nhap lai: ");
		fflush(stdin);
		gets(ps->nation);
	}
	
	printf("Nhap Name: ");
	fflush(stdin);
	gets(ps->name);
	fix(ps->name);
	while(strlen(ps->name) > 30)
	{
		printf("Khong hop le! Hay nhap lai: ");
		fflush(stdin);
		gets(ps->name);
		fix(ps->name);
	}
	
}

void chucnang1()
{
	cnt1++;
	
	printf("\nHay nhap so luong van dong vien: ");
	fflush(stdin);
	scanf("%d", &n);
	while(n <= 0 || n > 20)
	{
		printf("Khong hop le! Hay nhap lai: ");
		fflush(stdin);
		scanf("%d", &n);
	}
	
	int i, j;
	for(i = 1; i <= n; ++i)
	{
		printf("Nhap thong tin van dong vien thu %d: \n", i);
		getInf(&vdv[i], i);
	}
	
}

void chucnang2()
{
	int i, j;
	if(cnt2 == 0)
	{
		printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for(i = 1; i <= n; ++i)
		{
			printf("%-10d%-10s%-30s", vdv[i].id, vdv[i].nation, vdv[i].name);
			for(j = 1; j <= 4; ++j)
			{
				printf("%-10s", "");
			}
			printf("\n");
		}	
	} 
	else
	{
		printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for(i = 1; i <= n; ++i)
		{
			printf("%-10d%-10s%-30s", vdv[i].id, vdv[i].nation, vdv[i].name);
			for(j = 1; j <= 3; ++j)
			{
				printf("%-10.2f", vdv[i].R[j]);
			}
			printf("%-10.2f\n", vdv[i].ketqua);
		}	
	}
}

void FR(olympic *ps)
{
	int i;
	ps->ketqua = ps->R[1];
	for(i = 2; i <= 3; ++i)
	{
		if(ps->R[i] > ps->ketqua)
			ps->ketqua = ps->R[i];
	}
}

void chucnang3()
{
	cnt2++;
	
	printf("\nKet qua thi dau: \n");
	int i, j, k, p, l;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= 3; ++j)
		{
			vdv[i].R[j] = -1;
		}
	}
	
	for(i = 1; i <= 3; ++i)
	{
		printf("\nNhap ket qua lan %d: \n", i);
		for(j = 1; j <= n; ++j)
		{
			printf("Van dong vien thu %d: ", j);
			fflush(stdin);
			scanf("%f", &vdv[j].R[i]);
			while(vdv[j].R[i] < 0 || vdv[j].R[i] >= 20)
			{
				printf("Khong hop le! Nhap lai: ");
				fflush(stdin);
				scanf("%f", &vdv[j].R[i]);
			}
		}
		printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for(k = 1; k <= n; ++k)
		{
			printf("%-10d%-10s%-30s", vdv[k].id, vdv[k].nation, vdv[k].name);
			for(p = 1; p <= 3; ++p)
			{
				if(vdv[k].R[p] > -1)
					if(vdv[k].R[p] == 0) printf("%-10.0f", vdv[k].R[p]);
					else printf("%-10.2f", vdv[k].R[p]);
				else printf("%-10s", "");
			}
			if(i == 3)
			{
				for(l = 1; l <= n; ++l)
				{
					FR(&vdv[l]);
				}
				printf("%-10.2f\n", vdv[k].ketqua);
			}
			else printf("%-10s\n", "");
		}	
	}
	
}

int timten(char const *s1, char const *s2) {
	char *look = strcasestr(s1, s2);
	if(look == NULL) return 0;
	else return 1; 
}

int timquocgia(char const *s1, char const *s2) {
	int result = strcasecmp(s1, s2);
	if(result == 0) return 1;
	else return 0;
}

void chucnang4()
{
	int i, j, dem;
	
	int func;
	do
	{
		printf("\n1. Tim kiem theo quoc gia.\n2. Tim kiem theo ten van dong vien.\nNhap so khac de thoat!.\n");
		printf("\nHay chon 1 trong 3 chuc nang: ");
		fflush(stdin);
		scanf("%d", &func);
		/*while(func != 1 && func != 2)
		{
			printf("Khong hop le! Nhap lai: ");
			fflush(stdin);
			scanf("%d", &func);
		} */
		switch(func)
		{
			case 1:
				dem = 0; //dem xem co bao nhieu vdv thoa man
				char quocgia[10];
				printf("Nhap ten quoc gia muon tim kiem: ");
				fflush(stdin);
				gets(quocgia);
				for(i = 1; i <= n; ++i)
				{
					if(timquocgia(vdv[i].nation, quocgia) == 1)
					{
						dem++;
						if(dem == 1) 
						{
							printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
						}
						printf("%-10d%-10s%-30s", vdv[i].id, vdv[i].nation, vdv[i].name);
						for(j = 1; j <= 3; ++j)
						{
							printf("%-10.2f", vdv[i].R[j]);
						}
						printf("%-10.2f\n", vdv[i].ketqua);
					}
				}
				if(dem == 0) printf("\nKhong co!\n");
				break;
			case 2: 
				dem = 0;
				char ten[35]; //ten
				printf("Nhap ten van dong vien muon tim kiem: ");
				fflush(stdin);
				gets(ten);
				for(i = 1; i <= n; ++i)
				{
					char *result = strcasestr(vdv[i].name, ten);
					if(result)
					{
						dem++;
						if(dem == 1) 
						{
							printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
						}
						printf("%-10d%-10s%-30s", vdv[i].id, vdv[i].nation, vdv[i].name);
						for(j = 1; j <= 3; ++j)
						{
							printf("%-10.2f", vdv[i].R[j]);
						}
						printf("%-10.2f\n", vdv[i].ketqua);
					}
				}
				if(dem == 0) printf("\nKhong co!\n");
				break;
			default:
				break;
		}
	} while(func == 1 || func == 2);
}

void chucnang5()
{
	olympic tmp; //bien trung gian
	
	int i, j;
	for(i = 1; i < n; ++i)
	{
		for(j = i + 1; j <= n; ++j)
		{
			if(vdv[i].ketqua < vdv[j].ketqua)
			{
				tmp = vdv[i];
				vdv[i] = vdv[j];
				vdv[j]= tmp;
			}
		}
	}
	
	printf("\n%-10s%-10s%-30s%-10s%-10s%-10s%-10s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
	for(i = 1; i <= n; ++i)
	{
		printf("%-10d%-10s%-30s", vdv[i].id, vdv[i].nation, vdv[i].name);
		for(j = 1; j <= 3; ++j)
		{
			printf("%-10.2f", vdv[i].R[j]);
		}
		printf("%-10.2f\n", vdv[i].ketqua);
	}
}

void menu()
{
	int func;
	printf("Chuong trinh Olympic mon nhay xa: \n");
	do
	{
		printf("\n1. Nhap thong tin truoc thi dau.\n2. In thong tin.\n3. Thi dau.\n4. Tim kiem.\n5. In ket qua.\n6. Ket thuc");
		printf("\nHay chon chuc nang: ");
		fflush(stdin);
		scanf("%d", &func);
		switch(func)
		{
			case 1:
				if(cnt1 == 1)
				{
					printf("Chuc nang su dung 1 lan! Hay chon chuc nang khac!\n");
					break;
				}
				chucnang1();
				break;
			case 2:
				if(cnt1 == 0)
				{
					printf("Hay nhap thong tin truoc!\n");
					break;
				}
				chucnang2();
				break;
			case 3:
				if(cnt1 == 0)
				{
					printf("Hay nhap thong tin truoc!\n");
					break;
				}
				if(cnt2 == 1)
				{
					printf("Chuc nang su dung 1 lan! Hay chon chuc nang khac!\n");
					break;
				}
				chucnang3();
				break;
			case 4: 
				if(cnt1 == 0)
				{
					printf("Hay nhap thong tin truoc!\n");
					break;
				}
				if(cnt2 == 0)
				{
					printf("Phai co ket qua thi dau truoc!\n");
					break;
				}
				chucnang4();
				break;
			case 5:
				if(cnt1 == 0)
				{
					printf("Hay nhap thong tin truoc!\n");
					break;
				}
				if(cnt2 == 0)
				{
					printf("Phai co ket qua thi dau truoc!\n");
					break;
				}
				chucnang5();
				break;
			case 6:
				printf("\nCam on vi da su dung!\n");
				break;
			default:
				printf("So da nhap khong hop le!\n");
				break;
		}
	} while(func != 6);
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
	int i;
	//xoa dau
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	
	//xoa giua
	for(i = 0; i < strlen(s); ++i) {
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
	for(i = 0; i < strlen(s); ++i)
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
	for(i = 1; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
			if(!isupper(s[i + 1]))
				s[i + 1] -= 32;
	}
}
