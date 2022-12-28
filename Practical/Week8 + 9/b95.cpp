#include<stdio.h>
void printnchars(char ch, int n);
int main() {
	int n; 
	char ch;
	printf("Enter the character = "); scanf("%c", &ch);
	printf("Enter n = "); scanf("%d", &n);
	printnchars(ch, n);
	return 0;
}
void printnchars(char ch, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}
