#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
const int MAX = 1000;
char s[MAX], fname[MAX], name[MAX];
bool isblank(char c) {
	return c == ' ' || c == '\t' || c == '\n'; //true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',';
}
void trim() {
	int len = strlen(s);
	while(isblank(s[0]) || speC(s[0])) strcpy(&s[0], &s[1]);
	for(int i = 0; i < len; i++) {
		if(isblank(s[i]) && isblank(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
				i--;
				len--;
			}
		}
		if(speC(s[i]) && isblank(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
				i--;
				len--;
			}
		}
		if(isblank(s[i]) && speC(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
				i--;
				len--;
			}
		}
		if(speC(s[i]) && speC(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
				i--;
				len--;
			}
		}
	}
	while(isblank(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
}
void inverse() {
	for(int i = strlen(s) - 1; i >= 0; i--) {
		printf("%c", s[i]);
	}
}
void cpy() {
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == ' ') break;
		fname[i] = s[i];
		printf("%c", fname[i]);
	} printf(" -- ");
	for(int i = strlen(s) - 1; i >= 0; i--) {
		if(s[i] == ' ') break;
		name[i] = s[i];
	}
	for(int i = strlen(name) - 1; i >= 0; i--) printf("%c", name[i]);
}
int main() {
	fflush(stdin);
	gets(s);
	trim();
	printf("%s", s);
	printf("\n");
	cpy();
	printf("\n");
	inverse();

	return 0;
}
