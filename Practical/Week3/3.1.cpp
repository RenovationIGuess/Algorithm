#include<stdio.h>
int main() {
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(long));
	printf("%d%5d", sizeof(short), sizeof(char));
	return 0;
}
