#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int l = i + 1; l < n; l++) {
			if (arr[i] > arr[l]) {
				int a = arr[i];
				arr[i] = arr[l];
				arr[l] = a;
				
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
