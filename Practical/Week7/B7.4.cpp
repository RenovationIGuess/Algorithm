#include<stdio.h>
#include<math.h>
int main() {
	int n; scanf("%d", &n);
	printf("2 ");
	/* De xet xem no co la so nguyen to hay khong thi can phai:
	- n < 2: khong la so nguyen to
	- Xet 2 vong lap long trong nhau voi i = 3, j = 2, neu i chia het cho 1 so 
	nao do thuoc [2;sqrt(i)] thi i khong la so nguyen to va nguoc lai
	- Cung tu viec i khong chia het cho 1 so thuoc [2; can i] thi i cung khong 
	chia het cho so nao thuoc [can i; i - 1]
	 */
	 /* Giai thich thuat toan:
	 - 1 so khong la so nguyen to <=> n = a * b
	 - Neu ca a va b deu > can n => a * b > n, vi vay can it nhat 1 trong 2 thua 
	 so <= can n va neu khong ton tai ptu nao thoa man dieu do <=> voi moi a * b > n
	 thi n la so nguyen to */
	for (int i = 3; i <= n; i++) { 
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
			if (j > sqrt(i)) {
				printf("%d ", i);
				break;
			}
		}
	}
	return 0;
}
