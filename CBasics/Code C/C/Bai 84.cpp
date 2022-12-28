#include<stdio.h>
int lam(int arr[], int n) {
	if (n == 1) return arr[0]; //Neu n = 1 thi khi do n - 1 = 0
	return arr[n - 1] + lam(arr, n - 1);
}
int main() {
	int n;
	int arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d", lam(arr, n));
	return 0;
}
