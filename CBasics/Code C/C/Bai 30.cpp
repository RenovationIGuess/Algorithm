#include<stdio.h>
/* Toan tu || dung de kiem tra xem mot trong cac bieu thuc co dung khong, neu co thi menh de trong if duoc thuc thi; 
	Toan tu && thi tat ca cac bieu thuc phai dung thi doan code ben trong if moi duoc thuc thi */
int main() {
	int a; //Khai bao kieu so nguyen a
	scanf("%d", &a); //Nhap tu ban phim gia tri a
	if (a>0 || a <10) {
	
		printf("The score is valid");
	} else {
		printf("The score is not valid");
	}
	return 0; //Co the hieu toan tu && la va; toan tu || la hoac
}
