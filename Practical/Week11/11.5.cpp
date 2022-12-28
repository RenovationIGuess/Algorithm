#include<stdio.h>
void swap(int *p, int *q, int *r) {
	int tmp;
	tmp = *p; *p = *q; *q = *r; *r = tmp;
}
int main() {
	int x, y, z; scanf("%d%d%d", &x, &y, &z);
	int *p, *q, *r;
	p = &x; q = &y; r = &z;
	printf("Value of x, y, z: %d %d %d\n", x, y, z);
	printf("Value\np - %p\nq - %p\nr - %p\n", p, q, r);
	printf("Value of *p, *q, *r: %d %d %d\n", *p, *q, *r);
	swap(&x, &y, &z);
	printf("Value of x, y, z: %d %d %d\n", x, y, z);
	printf("Value\np - %p\nq - %p\nr - %p\n", p, q, r);
	printf("Value of *p, *q, *r: %d %d %d\n", *p, *q, *r);
	swap(p, q, r);
	printf("Value of x, y, z: %d %d %d\n", x, y, z);
	printf("Value\np - %p\nq - %p\nr - %p\n", p, q, r);
	printf("Value of *p, *q, *r: %d %d %d\n", *p, *q, *r);
	return 0;
}
