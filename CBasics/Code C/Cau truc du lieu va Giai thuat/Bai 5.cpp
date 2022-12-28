#include<stdio.h>
int main() {
	/* Khi xoa mot phan tu trong mang, so phan tu trong day giam di 1 don vi, cac phan tu tu 0 -> k - 1 giu nguyen
	cac phan tu tu k -> n - 1 giam chi so 1 don vi cung co nghia la a[i] = a[i + 1] voi i = k */
	int a[100];
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for (int i = k; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
