#include<stdio.h>
#include<math.h>
bool lam(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	int a[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if(lam(a[i])) {
			printf("%d ", a[i]);
		}
	}
	return 0;
}
