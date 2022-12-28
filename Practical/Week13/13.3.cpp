#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
bool check(char code[]) {
	for(int i = 0; i < 3; i++) {
		if(!isalpha(code[i])) return false;
	}	
	for(int i = 3; i < 7; i++) {
		if(!isdigit(code[i])) return false;
	}
	return true;
}
int main() {
	char code[8];
	fflush(stdin);
	gets(code);
	if(check(code)) printf("Correct!\n");
	else printf("Wrong!\n");
	return 0;
}
