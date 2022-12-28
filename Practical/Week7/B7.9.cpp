#include<stdio.h>
int main() {
	int n;
	printf("Enter your number: ");
	scanf("%d", &n);
	int a = 1;
	for (int i = n; i >= 1; i--) {
		a *= i;
	}
	printf("Result: %d! = %d.", n, a);
}
