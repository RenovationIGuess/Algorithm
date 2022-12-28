#include<stdio.h>
void lam(char str[100]) {
	scanf("%s", str);
	printf("%s", str);
}
int main() {
	char str[100];
	lam(str);
	return 0;
}
