/* Ham co the hieu la 1 doan code, khi goi ham tuc la ta dang goi den doan code nay (co the hieu ham la viet tat cua 1 doan code
Cach khai bao ve ham
#include<stdio.h>
//Khai bao ham man
void man() {
	//Hien thi ra man hinh cac so tu 1 den 10
	for (int i = 1; i <= 10; i++) {
		printf("%d", i);
	}
}
 int main() {
 	//Goi ham man
 	man();
 	return 0;
}
Neu o phan int main () {} ta goi ham 2 lan thi ket qua khi chay se co 2 day so
=> Cu phap de tao va su dung ham
void ten_ham() {
	/*Khoi lenh ben trong than ham
	Khoi lenh nay se duoc thuc thi khi ban goi ham
	*/
//De su dung ham don gian la goi ten ham
#include<stdio.h> 
void lam() {
	int i = 1;
	while (i <= 100) {
		printf("%d", i);
		i++;
	}
}
int main() {
	lam();
	return 0;
}
