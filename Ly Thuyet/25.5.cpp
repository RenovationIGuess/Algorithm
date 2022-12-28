#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int max(int a[], int n) {
	int tmp = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > tmp) tmp = a[i];
	}
	return tmp;
}
int min(int a[], int n) {
	int tmp = a[0];
	for (int i = 0; i < n; i++) {
		if(tmp > a[i]) tmp = a[i];
	}
	return tmp;
}
int main() {
	srand((int)time(0));
	int n, sum = 0; 
	n = rand() % (10 + 1 - 5) + 5; printf("n = %d\n", n);
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (100 + 1 - 1) + 1;
		printf("a[%d] = %d\n", i + 1, a[i]);
		sum += a[i];
	}
	printf("Min = %d\nMax = %d\nSum = %d", min(a, n), max(a, n), sum);
	return 0;
}
