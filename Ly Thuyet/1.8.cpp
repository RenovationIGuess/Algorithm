#include<stdio.h>
int main() {
	int n, cnt;
	printf("Enter n = "); scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		if(cnt) {
			if(cnt > 1) {
				for (int j = 0; j < cnt; j++) {
					printf("%d ", i);
				} 
			} else {
				printf("%d ", i);
			}
		}
	}
	return 0;
}
