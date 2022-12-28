#include<stdio.h>
int main() {
	int i, j, k;
	float a[3][3], b[3][3], c[3][3];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("a[%d][%d] = ", i, j); 
			scanf("%f", &a[i][j]);
			printf("b[%d][%d] = ", i, j); 
			scanf("%f", &b[i][j]); 
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			c[i][j] = 0;
			for (k = 0; k < 3; k++) {
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	printf("\nMatrix A: ");
	for(i = 0; i < 3; i++){
		printf("\n");
		for (j = 0; j < 3; j++) {
			printf("%.2f\t", a[i][j]);
		}
	}
	printf("\nMatrix B: ");
	for(i = 0; i < 3; i++){
		printf("\n");
		for (j = 0; j < 3; j++) {
			printf("%.2f\t", b[i][j]);
		}
	}
	printf("\nMatrix C: ");
	for(i = 0; i < 3; i++){
		printf("\n");
		for (j = 0; j < 3; j++) {
		printf("%.2f\t", c[i][j]);
		}
	}
	return 0;
}
