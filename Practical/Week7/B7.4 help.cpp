#include<stdio.h>
int main() {
	int n; //Tao bien check
	printf("Enter n: ");
	scanf("%d", &n);
	int Kiemtra = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				Kiemtra = 0; 
			}
		}
/* Sau khi ket thuc vong lap for con (j) ta duoc cac gia tri cua Kiem tra bao gom 0 va 1 */
		if (Kiemtra == 1) {
			printf("%d ", i);
		}
		Kiemtra = 1; //Gan lai cho Kiemtra = 1 de quay tro ve vong lap ban dau
	}
	return 0;
}
