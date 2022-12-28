#include<stdio.h>
int main() { //Day de bai la day Fibo
	float a = 1, b = 2, c; //De in ra day Fibo gom 100 so thi dung float de khong bi overflow
	int n;
	scanf("%d", &n); //Nhap so so Fibo muon in ra
	printf("%.0lf %.0lf", a, b);
	for(int i = 3; i < n; ++i) {
		c = a + b;
		printf(" %.0lf", c);
		a = b;
		b = c;
	}
	return 0;
}
