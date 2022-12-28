#include<stdio.h>
int main() {
	int a[7]= {13, -355, 235, 47, 67, 943, 1222};
	printf("Address of array's elements in memory:\n");
	int *p = &a[0];
	for (int i = 0; i < 5; i++) {
		printf("a[%d] = %d\na[%d]'s address = %p\n", i + 1, *(p + i), i + 1, (p + i));
	}
	return 0;
}
