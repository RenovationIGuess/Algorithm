#include<stdio.h>
int main() {
	int a, b;
	char c;
	scanf("%d %c %d", &a, &c, &b); //De nhap du lieu cho bien kieu ky tu dung ham scanf voi dinh dang %c
	/* Cau truc lenh switch case
		switch (x) {
	case gi�_tri_1:
		// Neu x c� gi� tri bang gi�_tri_1 th� doan code trong khoi lenh n�y se duoc thuc thi
		break;
	case gi�_tri_2:
		// Neu x c� gi� tri bang gi�_tri_2 th� doan code trong khoi lenh n�y se duoc thuc thi
		break;
	case gi�_tr?_3:
		// N?u x c� gi� tr? b?ng gi�_tr?_3 th� do?n code trong kh?i l?nh n�y s? du?c th?c thi
		break;
	...
	case gi�_tr?_n:
		// N?u x c� gi� tr? b?ng gi�_tr?_n th� do?n code trong kh?i l?nh n�y s? du?c th?c thi
		break;
	default:
		/* 
		N?u x kh�ng b?ng gi� tr? n�o trong c�c gi� tr? tr�n 
		th� code trong kh?i l?nh n�y s? du?c th?c thi
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
