#include<stdio.h>
int checkSymmetric(int a[], int n);
int main() {
	int n; 
	printf("Enter n = "); scanf("%d", &n);
	int a[n];
	printf("Array's' content:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i); scanf("%d", &a[i]);
	}
	if (checkSymmetric(a, n)) {
		printf("\nArray is symmetric.");
	} else printf("Array is not symmetric.");
	return 0;
}
int checkSymmetric(int a[], int n) {
	int i = 0, j = n - 1;
	while (i <= j) {
		if (a[i] != a[j]) return 0;
		i++;
		j--;
	}
	return 1;
}
