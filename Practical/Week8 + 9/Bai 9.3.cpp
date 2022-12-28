#include<stdio.h>
long sum1(int n) {
	int s = 0; //s: sum
	for (int i = 1; i <= n; i++) {
		s += i*i*i;
	}
	return s;
}
void print1(int n) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}
void print2(int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", i*i);
	}
	printf("\n");
}
int main() {
	int n; scanf("%d", &n);
	printf("%ld\n", sum1(n));
	print1(n);
	print2(n);
	return 0;
}

