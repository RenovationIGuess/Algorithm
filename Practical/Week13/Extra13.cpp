#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int n; //number of students
int func, cnt; //func = function, cnt will decide out or not
char stu[MAX][31], name[MAX][11];
void printName();
void sortName();
void Invalid();
void insert() {
	int count = 0; 
	fflush(stdin);
	printf("Services list:");
	do {
		printf("\n(1): Insert\t(2): print S.Name\t(3): Sort and print\t(4) Exit\n");
		printf("Choose a service: "); scanf("%d", &func);
		if(func > 4 || func <= 0) Invalid();
		while(func > 1 && func < 4 && count == 0) {
			printf("Insert first! (1) for insert, (4) to exit: "); 
			scanf("%d", &func);
			if(func == 4) return;
			if(func > 4 || func <= 0) Invalid();
		}
		if(func == 1 && count == 0) {
			count++;
			printf("Insert number of students (<100): "); scanf("%d", &n);
			for(int i = 0; i < n; i++) {
				printf("Student %d: ", i + 1);
				//scanf("%s", stu[i]);
				fflush(stdin);
				gets(stu[i]);
			}
		}
		else if(func == 1 && count != 0) {
			int e; //extra
			printf("Enter extra students: "); scanf("%d", &e);
			n = n + e;
			for(int i = n - e; i < n; i++) {
				printf("Student %d: ", i + 1); 
				//scanf("%s", stu[i]);
				fflush(stdin);
				gets(stu[i]);
			}
		}
		if(func == 2) {
			printName();
		}
		if(func == 3) {
			sortName();
		}
		if(func > 4 || func <= 0) {
			Invalid();
		}
	} while(func != 4);
}
void printName() {
	for(int i = 0; i < n; i++) {
		printf("Student %d name is: %s\n", i + 1, stu[i]);
	}
}
void sortName() { 
	for(int i = 0; i < n; i++) {
		int len = strlen(stu[i]);
		int k = strlen(stu[i]) - 1;
		int l = 0;
		while(k >= 0) {
			if(stu[i][k] == ' ') {
				for(int j = k + 1; j <= len; j++) {
					name[i][l] = stu[i][j];
					l++;
				}
				break; 
			}
			k--;
		}
	}
	char tmp[11];
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(name[i][0] > name[j][0]) {
				strcpy(tmp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], tmp);
			}
		}
	}
	printf("List of students name after sort:\n");
	for(int i = 0; i < n; i++) {
		printf("Student %d: %s\n", i + 1, name[i]);
	}
}
void Invalid() {
	printf("Invalid function! Choose from 1 -> 4: ");
	scanf("%d", &func);
	if(func > 4 || func <= 0) Invalid();
}
int main() {
	insert();
	printf("\n========================\n");
	printf("See you next time! (^_^)");
	return 0;
}
