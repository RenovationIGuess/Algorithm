#include<stdio.h>
int main() {
	char a, b, c; //d la ki tu dung dau
	scanf("%c %c %c", &a, &b , &c);
	if (a <= b && a <= c) {
		printf("%c", a);
	} else if (c >= b) {
		printf("%c", b);
	} else {
		printf("%c", c);
	}
	return 0;
}
