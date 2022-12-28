#include<stdio.h>
int main() {
	int a, b; 
	scanf("%d%d", &a, &b);
	int c = a; //Hoan doi gia tri 2 bien a, b bang cach tao ra bien trung gian c
	a = b; //3 dong 5,6,7 la cach de hoan doi 2 bien, khai bao bien c = a, cho a = b thi khi do b = c = a
	b = c;
	printf("after swapping, a = %d, b = %d", a, b); //Trong dau phay kep la cai hien thi ra man hinh, sau do phai nhap cac bien ngoai dau
	return 0;
}
