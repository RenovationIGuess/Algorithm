#include<stdio.h>
int lam(int arr[], int n) {
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			a++;
		}
	}
	return a;
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
