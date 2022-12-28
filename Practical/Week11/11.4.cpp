#include<stdio.h>
void swap(int *p, int *q, int *r) {
	int tmp;
	tmp = *p; *p = *q; *q = *r; *r = tmp;
}
int main() {
	int a, b, c;
	printf("Enter a, b, c: "); scanf("%d%d%d", &a, &b, &c);
	printf("Before swap: %d %d %d\n", a, b, c);
	swap(&a, &b, &c);
	printf("After swap: %d %d %d", a, b, c);
	return 0;
}
