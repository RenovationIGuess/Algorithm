#include<stdio.h>
#define MAX 101
#define for(i, a, b) for(int i = a; i <= b; i++)
int main() {
	int n;
	printf("Enter n = "); scanf("%d", &n);
	int *a = new int[n];
	printf("YCBT:\n");
	for(i, 1, n) {
		printf("a[%d] = ", i); scanf("%d", &a[i]);
	}
	for(i, 1, n) {
		printf("\n%d", a[i]);
		for(j, i, n - 1) {
			printf("\n");
			for(k, i, j + 1) {
				printf("%d ", a[k]);
			}
		}
	}
	delete []a;
	return 0;
}
