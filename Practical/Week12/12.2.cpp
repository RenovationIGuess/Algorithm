#include<stdio.h>
double maximum(double *a, int n) {
	double *max;
	max = &a[0];
	if(a == NULL) return NULL;
	for(int i = 0; i < n; i++) {
		if (a[i] > *max) *max = a[i];
	}
	return *max;
}
int main() {
	int n; 
	printf("Enter n = "); scanf("%d", &n);
	double a[n];
	for(int i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf("%lf", &a[i]);
	}
	printf("Largest num of the array = %.2f", maximum(a, n));
	return 0;
}
