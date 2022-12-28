#include<stdio.h>
int lam(int n) {
	if (n == 0) return 0;
	return n + lam(n - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", lam(n));
	return 0;
}
