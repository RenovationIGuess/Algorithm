#include<stdio.h>
#include<math.h>
int check(int n) {
	if (n == 1) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	} 
	return 1;
}
int main() {
	int n;
	printf("Enter n: "); scanf("%d", &n);
	for (int i = 2; i <= n/2; i++) { //Chi can xet den n/2 do cac uoc so thuc luon <= n/2
		if (check(n)) {
			printf("%d ", n);
			break;
		} //Neu a la so nguyen to thi in ra a luon
		while ((n % i == 0) && check(i)) {
				printf("%d ", i);
				n /= i;
		} //Vong lap nay co muc dich la de neu 1 so VD 24 = 2*2*2*3 thi 2 se dc in ra du so lan no xuat hien
		if (n == 1) break; //Sau khi vong lap gan ket thuc <=> n nho di va = 1 thi dung lai.
	}
	return 0;
}
