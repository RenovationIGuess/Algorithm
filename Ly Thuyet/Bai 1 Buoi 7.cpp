#include<stdio.h>
int main() {
	for(int i = 1, j = 9; i <= 9, j >= 0; i++, j--) {
		if (i + j == 10) {
			printf("%d%d\n", i, j);
		}
	}
	return 0;
}
