#include<stdio.h>
#include<string.h>
#include<ctype.h>
void replace(char s[], char a, char b) {
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == a) {
			s[i] = b;
		}
	}
}
int main() {
	char s[100], a, b; //a will be the be replaced by b
	fflush(stdin);
	gets(s);
	scanf("%c %c", &a, &b);
	printf("Before changed: %s\n", s);
	replace(s, a, b);
	printf("After changed: %s\n", s);
	return 0;
}
