#include<stdio.h>
int lam(int arr[], int n) {
	int a = arr[0]; //Khai bao a se la phan tu dai dien cho so lon nhat
	for (int i = 0; i < n; i++) {
		if (arr[i] > a) {
			a = arr[i];
		}					
	}
	return a; //Tao vong lap hoat dong nhu sau: neu arr[i] > a (buoc dau la a = arr[0]) thi a se = arr[i] va lap lai, khi do buoc tiep theo se la arr[i+1] > arr[i] => arr[i+1] = a va cu the
}
int main() {
	int n1, n2;
	int arr1[1000], arr2[1000];
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d", &arr2[i]);
	}
	printf("%d %d", lam(arr1, n1), lam(arr2, n2));
	return 0;
}
