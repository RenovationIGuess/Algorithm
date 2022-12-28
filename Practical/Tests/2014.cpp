#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
const int MAX = 19;
typedef struct {
	char id[6]; //mssv
	char name[31];
	float score[7]; //0 - HD; 1 - PB; 2, 3, 4 - HD 1, 2, 3; 5 - GK, 6 - CK
} stu;

stu list[MAX]; //khai bao mang 
int n, cnt; //so sinh vien, n < 20
char st[5][4] = {"HD", "PB", "HD1", "HD2", "HD3"}; //score type

int check(char s[]) { //Kiem tra ten khong co dau cach
	int i;
	for(i = 0; i < strlen(s); i++) {
		if(isspace(s[i])) return 1;
	}
	return 0;
}

int check1(char s[]) { //Kiem tra thua dau cach/ khoang trang
	if(isspace(s[strlen(s) - 1])) return 0;
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
	for(int i = 1; i < strlen(s); i++) {
		if(isupper(s[i]) != 0 && isspace(s[i - 1]) == 0) {
			return false;
		}
	}
	return true;
}

bool check4(stu *s)
{
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = i + 1; j < n; ++j)
			if(s->score[i] - s->score[j] > 3)
				return false;	
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
	while(check(s->name) == 0 || check1(s->name) == 0 || check3(s->name) == false) {
		printf("Khong hop le! Hay nhap lai: ");
		fflush(stdin);
		gets(s->name);
	}
	int i, j;
	for(i = 0; i < 5; i++) {
		printf("Nhap diem %s: ", st[i]);
		scanf("%f", &s->score[i]);
		while(s->score[i] < 0 || s->score[i] > 10) {
			printf("Khong hop le! Hay nhap lai: ");
			scanf("%f", &s->score[i]);
		}
	}
	while(!check4(s))
	{
		printf("\nDiem Da Nhap Khong Hop Le! Hay Nhap Lai: \n");
		for(i = 0; i < 5; i++) {
			printf("Nhap diem %s: ", st[i]);
			scanf("%f", &s->score[i]);
			while(s->score[i] < 0 || s->score[i] > 10) {
				printf("Khong hop le! Hay nhap lai: ");
				scanf("%f", &s->score[i]);
			}
		}
	}
}

int check3(stu *s) { //kiem tra diem > 5.5
	int i;
	for(i = 0; i < 5; i++) {
		if(s->score[i] <= 5.5) return 0;
	}
	return 1;
}

void print() {
	int i;
	printf("\n%-8s%-30sHD\tPB\tHD1\tHD2\tHD3\tGiua ky\tCuoi ky\n", "MSSV", "Ho va ten");
	for(i = 0; i < n; i++) {
		if(check3(&list[i]) == 1) {
			printf("%-8s%-30s%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", list[i].id, list[i].name, list[i].score[0],
			list[i].score[1], list[i].score[2], list[i].score[3], list[i].score[4], list[i].score[5], list[i].score[6]);
		}
	}
}

void print1() {
	int i;
	for(i = 0; i < n; i++) {
		if(check3(&list[i]) == 1) {
			list[i].score[5] = (list[i].score[0] + list[i].score[1])/2;
			list[i].score[6] = (list[i].score[2] + list[i].score[3] + list[i].score[4])/3;
		}
	}
	printf("\n%-8s%-30sHD\tPB\tHD1\tHD2\tHD3\tGiua ky\tCuoi ky\n", "MSSV", "Ho va ten");
	for(i = 0; i < n; i++) {
		printf("%-8s%-30s%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", list[i].id, list[i].name, list[i].score[0],
		list[i].score[1], list[i].score[2], list[i].score[3], list[i].score[4], list[i].score[5], list[i].score[6]);
	}
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
	printf("\n%-8s%-30sHD\tPB\tHD1\tHD2\tHD3\tGiua ky\tCuoi ky\n", "MSSV", "Ho va ten");
	for(i = 0; i < n; i++) {
		printf("%-8s%-30s%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n", list[i].id, list[i].name, list[i].score[0],
		list[i].score[1], list[i].score[2], list[i].score[3], list[i].score[4], list[i].score[5], list[i].score[6]);
	} 
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


