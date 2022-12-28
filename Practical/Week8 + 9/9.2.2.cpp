#include<stdio.h>
int check(int n) {
	int Kiemtra = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				Kiemtra = 0;
			}
		}
		if (Kiemtra == 1) {
			printf("%d", i);
		}
		Kiemtra = 1;
	}
	return Kiemtra;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i - 1; j++) {
			if (check(n) == 1) {
				printf("%d", i);
			}
		}
	}
	return 0;
}
