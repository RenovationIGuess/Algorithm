/*
switch (x) {
	case gi�_tr?_1:
		// N?u x c� gi� tr? b?ng gi�_tr?_1 th� do?n code trong kh?i l?nh n�y s? du?c th?c thi
		break;
	case gi�_tr?_2:
		// N?u x c� gi� tr? b?ng gi�_tr?_2 th� do?n code trong kh?i l?nh n�y s? du?c th?c thi
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
		//break;
	//} 
#include<iostream>
using namespace std;
int main() {
	int a, b;
	char c;
	cin >> a >> c >> b;
	switch (c) {
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			cout << a / b;
			break;
	}
	return 0;
}
