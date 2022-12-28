#include<stdio.h>
int main() {
	//i++ tuong duong voi i = i + 1 hoac i += 1
	//i-- tuong duong voi i = i - 1 hoac i -= 1
/* 	Vong lap for hieu don gian la lap lai 1 doan code vd nhu sau
	for (int i = 1; i <= 5; i++) {
		printf("%d", i);
	}
Cach hoat dong:
- Buoc 1: Tao ra bien i kieu nguyen va gan cho gia tri i = 1
- B2: neu i <= 5 thi thuc hien doan code ben trong dau {} (la doan code printf), nguoc lai neu i > 5 thi dung ko chay tiep sang B3
- B3: tang i len 1 don vi va quay lai buoc 2 (i++ tuong duong voi i = i + 1 hoac i += 1; i-- tuong duong voi i = i - 1 hoac i -= 1) */
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { //for (int khai bao; gia tri chay; tang hay giam bn) {}
		printf("%d " , i);
	}
	return 0;
}
