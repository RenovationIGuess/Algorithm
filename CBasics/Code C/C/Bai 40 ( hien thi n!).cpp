#include<stdio.h>
int main() {
	int n;
	// Bien luu tru ket qua cua n!
	// Luu y: can khoi tao gia tri cho bien nay = 1
	int l = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		l = l*i;
	}
	printf("%d", l);
	return 0;
}
