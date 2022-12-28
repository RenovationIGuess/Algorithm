#include<stdio.h>
#include<string.h>
#include<ctype.h>
/* int spacecounter(char s[]) {
	int cnt = 0;
	for(int i = 0; i < strlen(s); i++) {
		if(isspace(s[i])) count++;
	}
	return count;
} */
int spacecounter(char s[]) {
	int count = 0, i = 0;
	while(s[i] != '/0') {
		if(s[i] == ' ') {
			count++;
		}
		i++;
	}
	return count;
}
int main() {
	char s[100];
	fflush(stdin);
	gets(s);
	printf("Number of ' ' char are = %d", spacecounter(s));
	return 0;
}
