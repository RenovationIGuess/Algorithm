#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	// for hnhu co 3 dieu kien trong ngoac nen ( ; ; ) ???
	for (; n <= 100; n++) { //Neu lam for (int i = n; n <= 100; i++) no se lap lai ltuc :)???
		if (n % 2 == 0) { //Dang lam viec voi bien n nen khong can chen them i trung gian
			printf("%d ", n);
		}
	}
	return 0;
}
