/* == la toan tu kiem tra xem 2 gia tri co bang nhau khong, != la toan tu kiem tra xem 2 gia tri co khac nhau khong */
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("n is an even number");
	}
	if (n % 2 != 0) {
		printf("n is an odd number");
	}
	return 0;
}
