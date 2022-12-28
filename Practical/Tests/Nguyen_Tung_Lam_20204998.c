#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 20

typedef struct {
	char id[6]; //mssv
	char name[31];
	float score[7]; //0 - HD; 1 - PB; 2, 3, 4 - HD 1, 2, 3; 5 - GK, 6 - CK
} stu;

stu list[MAX]; //khai bao mang 
int n, cnt; //so sinh vien, n < 20
char st[7][50] = {"HD", "PB", "HD1", "HD2", "HD3", "Giua ky", "Cuoi ky"}; //score type

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);

int check(char s[]) { //Kiem tra ten khong co dau cach
	int i;
	for(i = 0; i < strlen(s); i++) {
		if(isspace(s[i])) return 1;
	}
	return 0;
}

int check1(char s[]) { //Kiem tra thua dau cach/ khoang trang
	if(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) return 0;
	return 1;
}

int check2(char s[], int l) { //Kiem tra co bi trung id khong
	int i;
	if(l == 0) return 1;
	for(i = 0; i < l; i++) {
		if(strcasecmp(list[i].id, s) == 0) return 0;
	}
	return 1;
}

bool check3(char s[]) { //kiemtra truoc chu in hoa co dau cach khong
	int i;
	for(i = 1; i < strlen(s) - 1; ++i) {
		if(isupper(s[i]) != 0 && isspace(s[i - 1]) == 0) {
			return false;
		} else if(isupper(s[i]) != 0 && isupper(s[i + 1]) != 0)
			return false;
	}
	return true;
}

bool check4(stu *s) //kiem tra diem da nhap co cach nhau hon 3
{
	int i, j;
	for(i = 0; i < n - 1; ++i)
		for(j = i + 1; j < n; ++j)
			if(s->score[i] - s->score[j] > 3 || s->score[j] - s->score[i] > 3)
				return false;	
	return true;
}

bool check6(char s[]) //kiem tra ten chu cai dau khong viet hoa
{
	if(islower(s[0])) return false;
	int i;
	for(i = 1; i < strlen(s); ++i)
	{
		if(islower(s[i]) && isspace(s[i - 1]))
			return false;
	}
	return true;
}

void getinf(stu *s, int l) {
	printf("\nHay nhap MSSV: "); 
	fflush(stdin);
	gets(s->id);
	while(check2(s->id, l) == 0 || strlen(s->id) > 5) {
		printf("MSSV khong hop le! Hay nhap lai: ");
		fflush(stdin);
		gets(s->id);
	}
	printf("Ten sinh vien: "); 
	fflush(stdin); 
	gets(s->name);
	while(!check(s->name) || !check1(s->name) || !check3(s->name) || !check6(s->name)) {
		printf("Khong hop le! Hay nhap lai: ");
		fflush(stdin);
		gets(s->name);
	}
	fix(s->name); //chuan hoa
	
	int i, j;
	for(i = 0; i < 5; i++) {
		printf("Nhap diem %s: ", st[i]);
		fflush(stdin);
		scanf("%f", &s->score[i]);
		while(s->score[i] < 0 || s->score[i] > 10) {
			printf("Khong hop le! Hay nhap lai: ");
			fflush(stdin);
			scanf("%f", &s->score[i]);
		}
	}
	
	while(!check4(s))
	{
		printf("\nDiem Da Nhap Khong Hop Le! Hay Nhap Lai: \n");
		for(i = 0; i < 5; i++) {
			printf("Nhap diem %s: ", st[i]);
			fflush(stdin);
			scanf("%f", &s->score[i]);
			while(s->score[i] < 0 || s->score[i] > 10) {
				printf("Khong hop le! Hay nhap lai: ");
				fflush(stdin);
				scanf("%f", &s->score[i]);
			}
		}
	}
}

int check5(stu *s) { //kiem tra diem > 5.5
	int i;
	for(i = 0; i < 5; i++) {
		if(s->score[i] <= 5.5) return 0;
	}
	return 1;
}

void print() {
	int i, j;
	printf("\n%-8s%-30s", "MSSV", "Ho va ten");
	for(i = 0; i < 7; ++i)
	{
		printf("%-10s", st[i]);
	} printf("\n");
	for(i = 0; i < n; i++) {
		if(check5(&list[i]) == 1) {
			printf("%-8s%-30s", list[i].id, list[i].name);
			for(j = 0; j < 7; ++j)
			{
				printf("%-10.1f", list[i].score[j]);
			}
			printf("\n");
		}
	}
	printf("\n");
}

void print1() {
	int i, j;
	for(i = 0; i < n; i++) {
		if(check5(&list[i]) == 1) {
			list[i].score[5] = (list[i].score[0] + list[i].score[1])/2;
			list[i].score[6] = (list[i].score[2] + list[i].score[3] + list[i].score[4])/3;
		}
	}
	printf("\n%-8s%-30s", "MSSV", "Ho va ten");
	for(i = 0; i < 7; ++i)
	{
		printf("%-10s", st[i]);
	} printf("\n");
	for(i = 0; i < n; i++) {
		printf("%-8s%-30s", list[i].id, list[i].name);
		for(j = 0; j < 7; ++j)
		{
			printf("%-10.1f", list[i].score[j]);
		}
		printf("\n");
	}
	printf("\n");
}

void insert() {
	int i;
	if(cnt == 0) {
		cnt++;
		printf("\nHay nhap so sinh vien: ");
		scanf("%d", &n);
		while(n < 0 || n > MAX) {
			printf("Khong hop le! Hay nhap lai: ");
			scanf("%d", &n);
		}
		for(i = 0; i < n; i++) {
			printf("Sinh vien thu %d: ", i + 1);
			getinf(&list[i], i);
		}
		print1();
	} else {
		int e; //extra
		printf("Hay nhap so sinh vien muon them: "); 
		scanf("%d", &e);
		while(n + e > MAX) {
			printf("Khong hop le! Hay nhap lai: ");
			scanf("%d", &e);
		} 
		n += e;
		for(i = n - e; i < n; i++) {
			printf("Sinh vien thu %d", i + 1);
			getinf(&list[i], i);
		}
		print1();
	}
}

char namae[MAX][11]; //luu ten

void sort() {
	int i, j, k, h, l;
	for(i = 0; i < n; i++) {
		int len = strlen(list[i].name);
		l = len - 1;
		h = 0;
	  	while(l >= 0) {
            if(list[i].name[l] == ' ') {
                for(j= l + 1; j <= len; j++) {
                    namae[i][h] = list[i].name[j];
					h++;
                }
                break;
            }
            l--;
        }
	}
	stu tmp;
	char tmp2[11];
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			//namae[i][0] > namae[j][0]
			if(strcmp(namae[i], namae[j]) > 0) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				strcpy(tmp2, namae[i]);
				strcpy(namae[i], namae[j]);
				strcpy(namae[j], tmp2);
			}
		}
	}
	
	printf("\n%-8s%-30s", "MSSV", "Ho va ten");
	for(i = 0; i < 7; ++i)
	{
		printf("%-10s", st[i]);
	} printf("\n");
	for(i = 0; i < n; i++) {
		printf("%-8s%-30s", list[i].id, list[i].name);
		for(j = 0; j < 7; ++j)
		{
			printf("%-10.1f", list[i].score[j]);
		}
		printf("\n");
	}
	printf("\n");
}

void menu() {
	int func; 
	printf("Chuong trinh tinh diem hoi dong tot nghiep sinh vien:\n");
	printf("Hay chon 1 trong cac chuc nang sau: \n");
	do {
		printf("(1). Insert.\n(2). List of successful protected students.\n(3). Sort.\n(4). Exit.\n");
		printf("Hay nhap chuc nang: "); scanf("%d", &func);
		switch(func) {
			case 1:
				insert();
				break;
			case 2: 
				if(cnt == 0) {
					printf("De su dung hay chon 1 truoc!\n");
					break;
				}
				print();
				break;
			case 3:
				if(cnt == 0) {
					printf("De su dung hay chon 1 truoc!\n");
					break;
				}
				sort();
				break;
			case 4: 
				printf("\nCam on vi da su dung dich vu cua chung toi!\n");
				//exit(0);
				break;
			default: 
				printf("Khong co chuc nang ban yeu cau! Hay nhap lai!\n");
				break;
		}
	} while(func != 4);
}

int main() {
	menu();
	return 0;
}

bool isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; //true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void fix(char s[]) {
	int i, j;
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

