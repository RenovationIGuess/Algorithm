#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int time0(int a[], int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt++;
		}
	}
	return cnt;
}
int string0(int a[], int n) {
	int count = 0, max = 0; 
	for (int i = 0; i < n; i++) {
		if(a[i] == 0) count++; 
		if (a[i] != 0) {
			if(count > max) {
				max = count;
				count = 0;
			}
		}	
	}
	if (count > max) max = count;
	return max; //Do dai chuoi 0 dai nhat
}
int main() {
	srand((int)time(0));
	int n = rand() % (10 + 1 - 5) + 5;
	int a[n];
	int c[101];
	for (int j = 0; j <= 100; j++) c[j] = 0;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (100 + 1 - 0) + 0;
		c[a[i]]++;
		printf("%d ", a[i]);
	} printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d-times = %d\n", a[i], c[a[i]]);
	}
	printf("0's appear times = %d\n", time0(a, n));
	printf("Longest 0 string = %d\n",string0(a, n));
	return 0;
}
