#include<stdio.h>
#include<string.h>
void lam(int n, char arr[]) {
	for (int i = 0; i < n; i++) {
		for (int l = i + 1; l < n; l++) {
			if (arr[i] < arr[l]) {
				int a = arr[i];
				arr[i] = arr[l];
				arr[l] = a;
			}
		}
	}
}
int main() {
	int n;
	char arr[n];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}	
	lam(n, arr);
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
