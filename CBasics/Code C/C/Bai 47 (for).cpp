// Khi gap lenh continue trong vong lap, cac doan code ben duoi continue se khong duoc thuc thi 
#include<stdio.h>
int main() {
	for (int i = 1; i <= 100; i ++) {
		if (i % 2 == 0) { // %: phep toan lay so du, neu i : 2 ma phan du = 0 thi lenh printf se dung
			continue;
		}
		printf("%d ", i); //Lenh continue o duoi lenh if tuc la: Neu dieu kien trong () cua if khong thoa man thi cau lenh printf o duoi continue se khong duoc hien hien VD: i = 2 khong thoa man => khong hien thi
	}
	return 0;
}
