#include<stdio.h>
void inc(int *p, int n) {
	for(int i = 0; i < n; i++) {
		p[i] += 2;
	}
}
int main() {
	int n; printf("Enter n: "); scanf("%d", &n);
	int *a = new int[n];
	for(int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	inc(a, n);
	printf("After increased:\n");
	for(int i = 0; i < n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	delete[]a;
	return 0;
}
