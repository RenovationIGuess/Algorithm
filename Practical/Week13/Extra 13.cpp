#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
/* Menu chuong tr�nh

Nh?p v�o h? t�n c?a 1 l?p sinh vi�n (s? lu?ng sv ko qu� 100, d? d�i t�n kh�ng qu� 30), sau d� in t?t c? t�n ra m�n h�nh. Ch� � ch?n l?i ch?c nang 1 l� nh?p th�m (kh�ng nh?p m?i).

C?t t�n c?a c�c b?n sinh vi�n v� in ra m�n h�nh (ch� � lo?i b? d?u c�ch ? cu?i t�n)

(Khuy?n kh�ch) S?p x?p theo t�n */
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
