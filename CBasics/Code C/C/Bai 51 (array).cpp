#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) { //Do co n so tinh tu 0 den n -1 => i < n
		scanf("%d", &a[i]); //Tao vong lap for de nhap gia tri cac bien
	}
	int maxValue = a[0]; //Tao gia tri cho max = a[0] TH kha nang nhat xra
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) {
			maxValue = a[i];
		}
	}
	printf("%d", maxValue);
	return 0;
}
