#include<stdio.h>
#define for(i, a, b) for(int i = a; i <= b; i++) 
void rev(int *p, int n) {
	int i = 0, j = n - 1, tmp;
	while(i < j) {
		tmp = *(p + i);
		*(p + i) = *(p + j);
		*(p + j) = tmp;
		i++; j--;
	}
}
int main() {
	int n;
	printf("Enter n = "); scanf("%d", &n);
	int a[n];
	printf("Enter array's elements:\n");
	for(i, 0, n - 1) {
		printf("a[%d] = ", i + 1);
		scanf("%d", &a[i]);
	}
	rev(a, n);
	printf("After reversed:\n");
	for(i, 0, n - 1) {
		printf("a[%d] = %d\n", i + 1, a[i]);
	}
	return 0;
}
