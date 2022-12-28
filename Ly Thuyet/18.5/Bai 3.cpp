#include<stdio.h>
int gt(int n) {
	if (n == 1) return 1;
	return n * gt(n - 1);
}
int main() {
	float sum = 0;
	for(int i = 1; i <= 5; i++) {
		sum += gt(i)/i;
	}
	printf("%.2f", sum);
	return 0;
}
