#include<stdio.h>
int main() {
	/* cach dung vong lap while:
		while (bieu thuc){
		//Neu bieu thuc dung thi thuc hien doan code trong khoi lenh nay;
	} */
	int n;
	scanf("%d", &n);
	while (n <= 100){ //Neu n <= 100 thi doan code ben trong {} duoc thuc thi
		if (n % 2 == 0) { //Neu n chia het cho 2 thi hien thi cac gia tri n
			printf("%d ", n);
		}
		n++; //Moi lan cau lenh if thoa man thi thuc thi lenh n++ tuc n tang len theo dieu kien 1 lan 
	}
	return 0;
}
