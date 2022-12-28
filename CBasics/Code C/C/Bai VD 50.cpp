#include<stdio.h>
int main() {
	//Khai bao mang a kieu so nguyen voi 10 phan tu
	int a[10];
	//Khai bao bien luu tru tong cac phan tu trong mang
	int b = 0;
	//Dung vong lap for de nhap du lieu cho cac phan tu trong mang
	for (int i = 0; i < 10; i++) { //a[0]... a[9] la 10 phan tu
		scanf("%d", &a[i]);
	}
	//Dung vong for de tinh tong cac phan tu trong mang
	for (int i = 0; i < 10; i++) {
		b += a[i]; // b = b + a[i] => b = b + a[1] + a[0]...
	}
	//In ra tong cac phan tu trong mang
	printf("%d", b);
	return 0;
}
