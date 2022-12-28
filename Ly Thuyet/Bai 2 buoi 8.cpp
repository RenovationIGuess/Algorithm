#include<stdio.h>
int check(int n) {
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) return 0;
	} 
	return 1;
}
int main() {
	int n; scanf("%d", &n);
	while(n) {
		n++;
		if(check(n)) {
			printf("%d", n);
			break;
		}
	}
	return 0;
}
