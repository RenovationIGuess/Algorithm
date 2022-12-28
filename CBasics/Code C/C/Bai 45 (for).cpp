#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (;a <= b; a++) {
		if (a % 3 == 0 && a % 5 == 0) {
			printf("%d ", a);
		}
	}
	return 0;
}
