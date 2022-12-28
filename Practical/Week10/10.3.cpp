#include<stdio.h>
int checkarray(int arr1[], int arr2[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr1[i] == arr2[i]) return 1;
	}
	return 0;
}
int main() {
	int n, arr1[n], arr2[n]; //n presents size of array
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int j = 0; j < n; j++) {
		scanf("%d", &arr2[j]);
	}
	printf("%d", checkarray(arr1, arr2, n));
	return 0;
}
