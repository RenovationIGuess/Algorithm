#include<stdio.h>
void lam() {
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 5 != 0) {
			printf("%d", i);
		}
	}
}
int main() {
	lam();
	return 0;
}
