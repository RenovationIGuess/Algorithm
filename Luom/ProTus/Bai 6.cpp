#include<stdio.h>
int UCNN(int a[], int b[]);
int BCLN(int a[], int b[]);
int main() {
	int n, m, count = 0, c = UCLN(b[0], b[1]), d = BCNN(a[0], a[1]); //n,m la so phan tu mang, count bien dem, c d la bien de tim so can tim
	do {
		scanf("%d %d", &n, &m);
	} while ((n <= 10 && n >= 1) && (m <= 10 && m >= 1));
	int a[n], b[m]; //Khai bao mang 1 n phan tu, mang 2 m phan tu
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
	if (x == y) {
		count++;
	}
	printf("%d", count);
	return 0;
}
int UCLN(int a, int b) { //Giai thuat Euclid
	if (b == 0) return a;
    return gcd(b, a % b);
}
int BCNN(int a, int b) {
	return a*b / UCLN(a,b);
}
