#include<stdio.h>
float PI(int n) {
	float sum = 0;
	for (int i = 1, count = 1; i <= 2*n + 1; i += 2, count++) {
		if(count % 2 == 0) {
			sum -= (float)1/i;
		} else {
			sum += (float)1/i;
		}
	}
	return sum*4;
}
int main() {
	int n;
	printf("Enter n: "); scanf("%d", &n);
	printf("PI = %lf", PI(n));
	return 0;
}
