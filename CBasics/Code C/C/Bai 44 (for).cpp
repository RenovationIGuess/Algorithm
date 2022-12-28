#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = 1;
	for (; b > 0; c *= a, b--); 
	printf("%d", c);
	
	return 0;
}
