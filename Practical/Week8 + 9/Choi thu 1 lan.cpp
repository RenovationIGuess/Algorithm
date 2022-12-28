#include<stdio.h>
int length(int x, int v);
int main() {
	int x1, v1, x2, v2; scanf("%d %d %d %d", &x1, &v1, &x2, &v2);
	for (int t = 0; t < 1000; t++) {
		if(length(x1, v1)*t == length(x2, v2)*t) {
			printf("YeS");
			break;
		} else {
			printf("NO");
		}
	}
	return 0;
}
int length(int x, int v) {
	int s = x;
	return s;
}
//Sai
