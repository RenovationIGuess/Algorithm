#include<stdio.h>
float converse(float n) {
	return (float)5/9*(n-32);
}
int main() {
	for (int i = 1; i <= 20; i++) {
		printf("%.2f\n", converse(i));
	}
	return 0;
}
