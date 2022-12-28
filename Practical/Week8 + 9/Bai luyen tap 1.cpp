#include<stdio.h>
int main() {
	int Diem;
	printf("Ban hay nhap diem: ");
	scanf("%d", &Diem);
	do {
		if (Diem < 0 || Diem > 10) {
			printf("Ban da nhap sai diem! Xin nhap lai: ");
			scanf("%d", &Diem);
		}
	} while (Diem < 0 || Diem > 10);
	printf("Diem ban da nhap la: %d", Diem);
	return 0;
}
