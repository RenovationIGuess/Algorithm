#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (i % 3 == 0) { //KN: co the long lenh nhu vay
			printf("%d ", i);
		}
	}
	return 0;
}
