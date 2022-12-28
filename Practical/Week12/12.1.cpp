#include<stdio.h>
#define for(i, a, b) for(int i = a; i <= b; i++)
int countOdd(int *p, int n) {
	int cnt =0;
	for (i, 1, n) 
		if(p[i] % 2 != 0) cnt++;
	return cnt;
}
int main() {
	int n; 
	printf("Enter n = "); scanf("%d", &n);
	int a[n];
	for(i, 1, n) {
		printf("Enter a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	printf("Number of oddnum = %d", countOdd(a, n));
	return 0;
}
