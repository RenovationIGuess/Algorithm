#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
const int total = 4;
typedef struct {
	char name[25];
	int old;
	int score[5];
} game;

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);
void res(char s[]);

int n, cnt; //n - number of players
game person[total];
char s[41];

void getinf(game *p) {
	printf("Name: "); 
	fflush(stdin);
	gets(p->name);
	fix(p->name);
	printf("Age: "); 
	fflush(stdin);
	scanf("%d", &p->old);
}

void display(game *p) {
	printf("%-25s%-10d\n", p->name, p->old);
}
int check() {
	int i;
	for(i = 0; i < n; i++) {
		if(isspace(s[i])) return 0;
	}
	return 1;
}
void insert() {
	int i;
	cnt++;
	printf("Enter the S string (20 to 40 characters): "); 
	fflush(stdin);
	scanf("%s", s); //gets(s);
	while(strlen(s) < 20 || strlen(s) > 40 || !check()) {
		printf("Invalid! Try again: ");
		fflush(stdin);
		scanf("%s", s); //gets(s);
	}
	printf("\nEnter number of players: ");
	fflush(stdin);
	scanf("%d", &n);
	while(n < 0 || n > total) {
		printf("Invalid! Please try again: "); 
		fflush(stdin);
		scanf("%d", &n);
	}
	printf("\nEnter player's infomation: \n");
	for(i = 0; i < n; i++) {
		printf("\nPlayer %d - th info:\n", i + 1);
		getinf(&person[i]);
	}
	printf("\n%-25s%-10s\n", "Ho va ten", "Tuoi");
	for(i = 0; i < n; i++) {
		display(&person[i]);
	}
}

char tmp[41], answer[41];

void play(game *p) {
	int i, j;
	for(i = 0; i < strlen(s); i++) {
		tmp[i] = '*';
	}
	char c;
	for(j = 0; j < 4; j++) {
		fflush(stdin);
		printf("\nEnter character you guess (you have %d chances left): ", 4 - j - 1);
		fflush(stdin);
		scanf("%c", &c); //getchar(c);
		for(i = 0; i < strlen(s); i++) {
			if(c == s[i]) {
				tmp[i] = c;
				p->score[j]++;
			} else if(c == s[i] - 32) {
				tmp[i] = c + 32;
				p->score[j]++;
			}
		}
		printf("The string: %s.\n", tmp);
	}
	printf("\nEnter your final answer: "); 
	fflush(stdin); 
	scanf("%s", answer); //gets(answer);
	//Co the them chuc nang tu dong xoa dau cach hoac bat nhap lai neu sai
	int a = strcmp(answer, s);
	if(a == 0) {
		printf("\nCorrect!\n");
		for(i = 0; i < 4; i++) {
			p->score[4] += p->score[i];
		} p->score[4] += 20;
	} else {
		printf("Better luck next time!\n");
		for(int i = 0; i < 4; i++) {
			p->score[4] += p->score[i];
		}
	}
}
void start() {
	int i, j;
	for(i = 0; i < strlen(s); i++) {
		tmp[i] = '*';
	}
	printf("The string: %s\n", tmp); 
	printf("String length is: %d\n", strlen(tmp));
	printf("\nStart playing: \n");
	for(i = 0; i < n; i++) {
		printf("Player %d - %s turn:\n", i + 1, person[i].name);
		play(&person[i]);
	}
	printf("\n%-25s%-10s%-10s%-10s%-10s%-15s\n", "Ho va ten", "L1", "L2", "L3", "L4", "Ket qua");
	for(i = 0; i < n; i++) 
	{
		printf("%-25s", person[i].name);
		for(j = 0; j < 5; ++j)
		{
			printf("%-10d", person[i].score[j]);
		} printf("\n");
	}
}

void result() {
	int i, j;
	game tmp;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(person[i].score[4] < person[j].score[4]) {
				tmp = person[i];
				person[i] = person[j];
				person[j] = tmp;
			}
		}
	}
	printf("%-10s%-25s%-20s\n", "STT", "Ho va ten", "Do sai lech");
	for(i = 0; i < n; i++) {
		printf("%-10d%-25s%-20d\n", i + 1, person[i].name, person[i].score[4]);
	}
}

void menu() {
	int func, con;
	printf("Welcome to the game menu!\n");
	printf("Here are our services:\n");
	do {
		printf("(1). Start the game.\n(2). Play.\n(3). Result.\n(4). Exit\n");
		printf("Choose: "); scanf("%d", &func);
		while(func < 1 || func > 4) {
			printf("Invalid! Try again: "); 
			scanf("%d", &func);
		}
		switch(func) {
			case 1:
				insert();
				break;
			case 2: 
				if(cnt == 0) {
					printf("Please set up the game first!");
					break;
				}
				start();
				break;
			case 3:
				if(cnt == 0) {
					printf("Please set up the game first!");
					break;
				}
				result();
				break;
			case 4: 
				printf("\nThank you for using our services!\n");
				exit(0);
			default: 
				printf("Invalid number! Please try again: ");
				break;
		}
	printf("\nDo you want to continue (1). Yes/ (2). No: ");
		scanf("%d", &con);
		while(con < 1 || con > 2) {
			printf("Invalid! Try again: ");
			scanf("%d", &con);
		}
	} while(con == 1);
	printf("\nThank you for using our services!\n");
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
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	for(int i = 0; i < strlen(s); i++) {
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
	while(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
}
/*void res(char s[]) { //res - reset
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			for(int j = i + 1; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		}
	}
} */
