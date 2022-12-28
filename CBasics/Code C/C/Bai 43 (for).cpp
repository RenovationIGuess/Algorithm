#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			a++; // Neu moi lan thoa man thi + 1
		} /* Voi moi lan cau lenh duoc lap lai ma dieu kien trong () duoc thoa man thi lenh a++ lai duoc thuc hien, nghia la moi la thoa man a se tang len 1;
		 VD: n = 3 thi i = 1 thoa man, i = 3 thoa man => lenh dc lap lai 2 lan a = 1 => a++ tuong duong a = a + 1; */
	}
	printf("%d", a);
	return 0; 
	
}
