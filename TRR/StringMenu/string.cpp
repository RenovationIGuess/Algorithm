#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
const int MAX = 1000;
bool isblank(char c) {
	return c == ' ' || c == '\t' || c == '\n'; //true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void trim(char s[]) {
	while(isblank(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	for(int i = 0; i < strlen(s); i++) {
		if(isblank(s[i]) && isblank(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(isblank(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && isblank(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	while(isblank(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
}
void inverse(char s[]) {
	for(int i = strlen(s) - 1; i >= 0; i--) {
		printf("%c", s[i]);
	} printf("\n");
}
void fnn(char s[]) { //first name - name 
	int n = 0; 
	char name[MAX], fname[MAX];
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == ' ') break;
		fname[i] = s[i];
		printf("%c", fname[i]);
	} printf(" -- ");
	for(int i = strlen(s) - 1; i >= 0; i--) {
		if(s[i] == ' ') break;
		name[n] = s[i];
		n++;
	}
	for(int i = n - 1; i >= 0; i--) {
		printf("%c", name[i]);
	}
}
int main() {
	char s[MAX];
	fflush(stdin);
	gets(s);
	trim(s);
	printf("'%s'\n", s);
	inverse(s); 
	fnn(s);
	return 0;
}
