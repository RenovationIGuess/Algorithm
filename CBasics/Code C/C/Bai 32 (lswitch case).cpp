#include<stdio.h>
int main() {
	int a, b;
	char c;
	scanf("%d %c %d", &a, &c, &b); //De nhap du lieu cho bien kieu ky tu dung ham scanf voi dinh dang %c
	/* Cau truc lenh switch case
		switch (x) {
	case giá_tri_1:
		// Neu x có giá tri bang giá_tri_1 thì doan code trong khoi lenh này se duoc thuc thi
		break;
	case giá_tri_2:
		// Neu x có giá tri bang giá_tri_2 thì doan code trong khoi lenh này se duoc thuc thi
		break;
	case giá_tr?_3:
		// N?u x có giá tr? b?ng giá_tr?_3 thì do?n code trong kh?i l?nh này s? du?c th?c thi
		break;
	...
	case giá_tr?_n:
		// N?u x có giá tr? b?ng giá_tr?_n thì do?n code trong kh?i l?nh này s? du?c th?c thi
		break;
	default:
		/* 
		N?u x không b?ng giá tr? nào trong các giá tr? trên 
		thì code trong kh?i l?nh này s? du?c th?c thi
		*/
	/*	break;
	} */
	switch (c) {
		case '+': //Neu la chu so (1 hang so) thi khong can cho vao dau nhay don
			printf("%d", a + b); //
			break;
		case '-':
			printf("%d", a - b);
			break;
		case '*':
			printf("%d", a * b);
			break;
		case '/':
			printf("%d", a / b);
			break;
	}
	return 0;
}
