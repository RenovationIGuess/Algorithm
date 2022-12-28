#include<stdio.h>
#include<math.h>
int check(int n); //Prototype
int main() {
	int n;
	printf("Enter n: "); scanf("%d", &n);
	int a = n/2;
	for (int i = 2; i <= a; i++) {
		if (check(n)) {
			printf("%d ", n); 
			break;
		}
		while (n % i == 0 && check(i)) {
			printf("%d ", i);
			n /= i;
		}
		if (n == 1) break;
	}
	return 0;
}
int check(int n) {
	if (n == 1) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
