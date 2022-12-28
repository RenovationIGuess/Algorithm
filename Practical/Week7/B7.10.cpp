#include<stdio.h>
int main() {
	int n, a;
	printf("Enter n = ");
	scanf("%d", &n);
	if (n < 6) {
		printf("No numbers meet your request.\n");
	}
	 //Gan gia tri = 1 do tong chua 1 VD 6 = 1 + 2 + 3;
	//Bo qua 1 vi 1 khong phai so hoan hao
	/* Do so hoan hao = tong cac uoc cua no (khong tinh chinh no 
	nen ta co j <= i/2 de thu hep vong lap (uoc khong tinh chinh so do 
	<= so do/2) */
	for (int i = 2; i <= n; i++) {
		a = 1;
		for (int j = 2; j <= i/2; j++) {
			if (i % j == 0) {
				a += j;
			}			
 		}
		 if (a == i) {
			printf("%d ", i);
		}
 	}	
	return 0;
}
