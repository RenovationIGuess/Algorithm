/* do {
	//Khoi lenh
} while (bieu thuc); Cach doan code thuc hien:
Dau tien khoi lenh ben trong vong lap do - while se duoc thuc thi truoc. Sau do vong lap
do - while se kiem tra bieu thuc dieu kien, neu bieu thuc dieu kien dung thi chg trinh se tiep tuc thuc thi khoi lenh trong do - while,
ngc lai neu bieu thuc dieu kien sai thi dung vong lap.
do - while khac voi while o cho vong lap while se kiem tra dieu kien truoc, con vong lap do - while se thuc hien khoi lenh truoc nen khoi lenh trong do - while se duoc thuc thi it nhat 1 lan.
*/
#include<stdio.h>
int main() {
	int i = 1;
	do {
		printf("%d ", i);
		i++;
	} while (i <= 5);
	
	return 0;
}
