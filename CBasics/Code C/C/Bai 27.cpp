#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b); 
	/*  Bai toan yeu cau kiem tra xem a vs b khac hay = 0 binh thuong ta se dung 2 lenh if, nhung ta co the ket hop 2 cau lenh if cung tinh chat bang toan tu && */
	if (a != 0 && b != 0) {
		printf("a is not equal to 0 or b is not equal to 0");
	} else {
		printf("a is equal to 0 or b is euqual to 0");
	}
	return 0;
}
