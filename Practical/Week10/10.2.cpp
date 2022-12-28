#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int n; scanf("%d", &n);
	int a[n];
	srand((int)time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (100 + 1 - 1) + 1;
		printf("%d ", a[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) sum += a[i];
	}
	printf("YCBT = %d", sum);
	return 0;
}
