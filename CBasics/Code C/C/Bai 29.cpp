#include<stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	if (a > 10 && a < 100) {
	 //De kiem tra xem a co nam trong doan [10, 100] ta dung toan tu //
	 printf(" %d is in range (10;100)", a);
	} else {
		printf(" %d is not in range (10;100)", a);
	}
	return 0;
}
