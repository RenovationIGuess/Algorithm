#include<stdio.h>
#define for(i, a, b) for(int i = a; i <= b; i++)
void getSale(int *a) {
	for(i, 1, 12) {
		printf("Sales month %d = ", i); scanf("%d", &a[i]);
	}
}
int totalSale(int *a) {
	int sum = 0;
	for(i, 1, 12) {
		sum += a[i];
	}
	return sum;
}
int main() {
	int a[12];
	getSale(a);
	printf("Totalsale of the year = %d", totalSale(a));
	return 0;
}
