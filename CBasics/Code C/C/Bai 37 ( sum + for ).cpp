#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	// sum la bien luu tru tong cac so tu a toi b
	// Luu y: can phai gan gia tri cho sum = 0
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum = sum + i;
	}
	printf("%d", sum);
	return 0;
}
