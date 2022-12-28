// Viet chuong trinh nhap tu ban phim so nguyen n va hien thi ra man hinh so cac uoc so cua n
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int i = 1; //Khai bao 1 so nguyen i de lay lam moc
	int a = 0; //Gia tri dac trung cho so cac uoc so
	while (i <= n) {
		if (n % i == 0) { // n chia het cho i
			a++; // moi lan lenh duoc thuc hien la 1 lan + 1
		}
		i++; // i tang 1 don vi tu 1 den n
	}
	printf("%d", a);
	return 0;
}
