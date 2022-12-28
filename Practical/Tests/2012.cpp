#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define total 5

int cnt = 0, cnt2 = 0;
int n; //so nguoi choi
float num; //so can doan

typedef struct {
	char name[25];
	int old;
	float suggest[6]; 
} final;

final person[total];

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);

int check(char s[]) {
	int i;
	for(i = 1; i < strlen(s); i++) {
		if(isupper(s[i]) != 0 && isspace(s[i - 1]) == 0) {
			return 0;
		}
	}
	return 1;
}

void getinf(final *p) {
	printf("Nhap ten nguoi choi: "); 
	fflush(stdin); 
	gets(p->name);
	fix(p->name);
	while(strlen(p->name) > 25 || check(p->name) == 0) {
		printf("Ten nhap sai cu phap!\nHay nhap lai: ");
		fflush(stdin); 
		gets(p->name);
		fix(p->name);
	}
	printf("Hay nhap tuoi cua nguoi choi: "); 
	fflush(stdin); 
	scanf("%d", &p->old);
}

void insert() {
	cnt++;
	int i;
	printf("Nhap so can doan: ");
	fflush(stdin); 
	scanf("%f", &num);
	while(num < 0 || num > 100) {
		printf("So da nhap khong hop le! Hay nhap lai: ");
		fflush(stdin);
		scanf("%f", &num);
	}
	printf("Hay nhap so nguoi choi: "); 
	fflush(stdin); 
	scanf("%d", &n);
	while(n < 0 || n > total) {
		printf("So nguoi choi khong hop le! Hay nhap lai: "); 
		fflush(stdin);
		scanf("%d", &n);
	}
	for(i = 0; i < n; i++) {
		printf("Hay nhap thong tin nguoi choi %d: \n", i + 1); 
		getinf(&person[i]);
	}
	printf("%-25s%-10s\n", "Ho va ten", "Tuoi");
	for(i = 0; i < n; i++) {
		printf("%-25s%-10d\n", person[i].name, person[i].old);
	}
}

void play() {
	cnt2++;
	int i, j, k;
	for(i = 0; i < n; i++) {
		printf("Luot cua nguoi choi thu %d - %s\n", i + 1, person[i].name);
		for(j = 0; j < 6; j++) {
			printf("Lan doan thu %d: ", j + 1);
			fflush(stdin); 
			scanf("%f", &person[i].suggest[j]);
			if(person[i].suggest[j] > num) 
			{
				printf("So ban doan lon hon dap an!\n");
				continue;
			}
			else if(person[i].suggest[j] < num)
			{
				printf("So ban doan nho hon dap an!\n");
				continue;
			}
			if(person[i].suggest[j] == num) {
				for(k = j + 1; k < 6; k++) {
					person[i].suggest[k] = 0;
				}
				printf("Ban da doan dung!\n");
				break;
			}
		}
	}
	printf("%-25s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Ho va ten", "L1", "L2", "L3", "L4", "L5", "L6");
	for(i = 0; i < n; i++) {
		printf("%-25s", person[i].name);
		for(j = 0; j < 6; j++) 
		{
			if(person[i].suggest[j] == 0) printf("%-10s", "");
			else printf("%-10.1f", person[i].suggest[j]);
		} 
		printf("\n");
	}
}

void sumup() {
	float res[total];
	int i, j;
	for(i = 0; i < n; i++) {
		if(person[i].suggest[5] != 0) {
			res[i] = (person[i].suggest[5]/num) - 1;
			if(res[i] < 0) res[i] = -res[i];
		} else res[i] = 0;
	}
	float tmp;
	final tmp2;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(res[i] > res[j]) {
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
				tmp2 = person[i];
				person[i] = person[j];
				person[j] = tmp2;
			}
		}
	}
	printf("%-10s%-25s%-20s\n", "STT", "Ho va ten", "Do sai lech");
	for(i = 0; i < n; i++) {
		if(res[i] == 0) printf("%-10d%-25s%-20.0f\n", i + 1, person[i].name, res[i]);
		else printf("%-10d%-25s%-20.3f\n", i + 1, person[i].name, res[i]);
	}
}

void menu() {
	int func, cont;
	printf("Hay chon cac chuc nang sau: \n");
	do {
		printf("\n(1). Khoi dong tro choi.\n(2). Choi doan so.\n(3). Tong hop ket qua.\n(4). Thoat chuong trinh.\n");
		printf("Hay nhap chuc nang muon su dung: "); scanf("%d", &func);
		switch(func) {
			case 1: 
				insert();
				break;
			case 2: 
				if(cnt == 0) {
					printf("Hay khoi tao tro choi truoc!\n"); 
					break;
				} 
				play();
				break;
			case 3:
				if(cnt == 0) {
					printf("Hay khoi tao tro choi truoc!\n"); 
					break;
				}  
				if(cnt2 == 0) {
					printf("Hay choi tro choi truoc!\n");
					break;
				}
				sumup();
				break;
			case 4: 
				printf("\nCam on vi da su dung chuong trinh!\n");
				exit(0);
			default:
				printf("So da nhap khong hop le! Hay thu lai!\n");
				break;
		}
		printf("Ban co muon tiep tuc khong (1). Co ,(2). Khong: "); scanf("%d", &cont);
	} while(cont == 1);
	printf("\nCam on vi da su dung chuong trinh!\n");
}

int main() {
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
			if(!isupper(s[i + 1])) //islower(s[i])
				s[i + 1] -= 32;
	}
}
