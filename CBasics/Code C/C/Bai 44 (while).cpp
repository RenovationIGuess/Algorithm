#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	// Tao 1 bien luu tru ket qua cua a mu b
	// Luu y: phai khoi tao gia tri cho bien = 1 (do a, b deu nguyen duong nen min a mu b = 1)
	int c = 1;
	while (b > 0) { // o day ta cho bieu thuc la b, tuc la neu nhap tu ban phim gia tri b thoa man dieu kien torng () thi lenh trong {} se duoc thuc thi
		// c *= a tuong duong voi c = c * a
		c *= a; /* c la ket qua cua a mu b, moi lan doan code duoc thuc thi VD:
		a = 2, b = 3 => voi b = 3 thoa man b > 0 doan code c = c* a duoc thuc hien tuong duong voi c = 1 * a
					 => voi b = 2 thoa man => c = c * a <=> c = a * a cu nhu the den khi b = 1 do b nguyen duong */
		b--; // a mu b a * a * a ... tat ca b lan
	}
	printf("%d", c);
	return 0;
}
