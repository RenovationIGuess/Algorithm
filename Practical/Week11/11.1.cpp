#include<stdio.h>
int main() {
	int a, b, c;
	printf("Enter a, b ,c: "); scanf("%d%d%d", &a, &b, &c);
	int *p;
	printf("The three integers are:\n");
	p = &a; printf("a = %d\n", *p);
	p = &b; printf("b = %d\n", *p);
	p = &c; printf("c = %d\n", *p);
	return 0;
}
