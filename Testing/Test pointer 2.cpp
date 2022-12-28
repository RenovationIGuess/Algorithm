#include<stdio.h>
#define for(i, a, b) for(int i = a; i <= b; i++)
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int **a; //Pointer lvl 2
	a = new int*[n]; //a points to array which has n pointers lvl 1
	for(i, 1, n) {
		a[i] = new int[m]; //a[i] is what a point to, a[i] is an array which has m elements
	}
	for(i, 1, n) {
		for(j, 1, m) {
			scanf("%d", &a[i][j]);
		}
	}
	for(i, 1, n) {
		int sum = 0;
		for(j, 1, m) {
			sum += a[i][j];
		}
		printf("Sum of line %d = %d\n", i, sum);
	}
	for(i, 1, n) {
		delete[]a[i];
	}
	delete[]a;
	return 0;
}
