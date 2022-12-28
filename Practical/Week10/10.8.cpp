#include<stdio.h>
/*void reverse(float a[], int n) {
	float tmp;
	for (int i = 0; i < n; i++) {
		tmp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tmp;
	}
}*/
int main() {
	int n; 
	printf("Enter n = "); scanf("%d", &n);
	float a[n];
	printf("Array's elements:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf("%f", &a[i]);
	}
	printf("After reversed we have:\n");
	float tmp;
	for (int i = 0; i < n/2; i++) {
		tmp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tmp;
	}
	for (int i = 0; i < n; i++) {
		printf("a[%d] = %.2f\n", i, a[i]);
	}
	return 0;
}
