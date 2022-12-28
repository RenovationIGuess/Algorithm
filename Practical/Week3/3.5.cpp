#include<stdio.h>
int main() {
	printf("Enter m & n (with m < n)\n");
	int m, n;
	printf("Enter m here: ");
	scanf("%d", &m);
	printf("Enter n here: ");
	scanf("%d", &n);
	int sum = 0;
	for(int i = m; i <= n; i++) {
		sum += i;
	}
	printf("Accumulated sum = %d", sum);
	return 0;
}
