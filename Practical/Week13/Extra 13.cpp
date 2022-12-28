#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
/* Menu chuong trình

Nh?p vào h? tên c?a 1 l?p sinh viên (s? lu?ng sv ko quá 100, d? dài tên không quá 30), sau dó in t?t c? tên ra màn hình. Chú ý ch?n l?i ch?c nang 1 là nh?p thêm (không nh?p m?i).

C?t tên c?a các b?n sinh viên và in ra màn hình (chú ý lo?i b? d?u cách ? cu?i tên)

(Khuy?n khích) S?p x?p theo tên */
int n; //number of students
int func, cnt; //func = function, cnt will decide out or not
char sname[MAX][11]; char name[MAX][11]; char fname[MAX][11]; //family name, sur name, name
void printName();
void sortName();
void Invalid();
void insert() {
	int count = 0; 
	fflush(stdin);
	printf("Services list:");
	do {
		printf("\n(1): Insert\t(2): print S.Name\t(3): Sort and print\n");
		printf("Choose a service: "); scanf("%d", &func);
		if(func > 4 || func <= 0) Invalid();
		if(func != 1 && count == 0) {
			printf("Insert first! (1) for insert, (4) to exit: "); 
			scanf("%d", &func);
			if(func > 4 || func <= 0) Invalid();
		}
		if(func == 1 && count == 0) {
			count++;
			printf("Insert number of students (<100): "); scanf("%d", &n);
			for(int i = 1; i <= n; i++) {
				printf("Student %d: ", i);
				scanf("%s %s", fname[i], sname[i]); getchar(name[i]);
			}
		}
		else if(func == 1 && count != 0) {
			int e; //extra
			printf("Enter extra students: "); scanf("%d", &e);
			n = n + e;
			for(int i = n - e + 1; i <= n; i++) {
				printf("Student %d: ", i); 
				scanf("%s %s %s", fname[i], sname[i], name[i]);
			}
		}
		if(func == 2) {
			printName();
		}
		if(func == 3) {
			sortName();
			for(int i = 1; i <= n; i++) {
				printf("Student %d name: %s\n", i, name[i]);
			}
		}
		if(func > 4 || func <= 0) {
			Invalid();
		}
	} while(func != 4);
	printf("\n========================\n");
	printf("See you next time! (^_^)");
}
void printName() {
	for(int i = 1; i <= n; i++) {
		puts(stu[i]);
	}
}
void Invalid() {
	printf("Invalid function! Choose from 1 -> 4: ");
	scanf("%d", &func);
	if(func > 4 || func <= 0) Invalid();
}
void sortName() {
	char str[11], str2[11], str3[11]; //as temporary
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(name[i][0] > name[j][0]) {
				strcpy(str, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], str);
				strcpy(str2, fname[i]);
				strcpy(fname[i], fname[j]);
				strcpy(fname[j], str2);
				strcpy(str3, sname[i]);
				strcpy(sname[i], sname[j]);
				strcpy(sname[j], str3);
			} 
		}
	}
}
int main() {
	insert();
	return 0;
}
