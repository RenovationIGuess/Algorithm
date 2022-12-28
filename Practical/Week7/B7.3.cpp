#include<stdio.h>
int main() {
	int n = 0; //n is the number of numbers larger than 27 from 1 to 100
	for (int i = 1; i <= 100; i++) {
		if (i > 27) {
			n++;
		}
	}
	printf("%d", n);
}
