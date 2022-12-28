#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int max(int a[]) {
	int tmp = a[0];
	for (int i = 0; i < 20; i++) {
		if (a[i] > tmp) {
			tmp = a[i];
		}
	}
	return tmp;
}
int sum(int a[]) {
	int t = 0;
	for (int i = 0; i < 20; i++) {
		t += a[i];
	}
	return t;
}
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
int main() {
	int a[20];
	srand((int)time(0));
	for (int i = 0; i < 20; i++) {
		a[i] = random(1,100);
		printf("%d ", a[i]);
	}
	printf("\nMax = %d\nSum = %d", max(a), sum(a));
	return 0;
}
