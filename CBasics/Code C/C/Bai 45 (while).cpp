#include<stdio.h>
int main() {
	int a, b; //Khai bao bien kieu so nguyen a, b
	scanf("%d%d", &a, &b); //Nhap tu ban phim
	while (a <= b) { //Dieu kien trong ngoac thoa man => doan code duoc thuc thi 
		if (a % 3 == 0 && a % 5 == 0) { //DK thoa man => run
			printf("%d ", a); //Hien thi so nguyen a
		}
		a++; /* Moi lan doan code duoc thuc thi a lai tang 1 lan VD:
		a = 1, b = 30 => a, b thoa man so nguyen va a <= b
		Doan code duoc thuc hien lan thu 1: a = 15 thoa man dieu kien cua if => hien thi gia tri a
		Do de bai yeu cau day so tu a toi b => dung a++ de sau do a = 30 duoc xep sau a = 15
	}
	return 0;
}
