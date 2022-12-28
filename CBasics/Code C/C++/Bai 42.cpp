/*
switch (x) {
	case giá_tr?_1:
		// N?u x có giá tr? b?ng giá_tr?_1 thì do?n code trong kh?i l?nh này s? du?c th?c thi
		break;
	case giá_tr?_2:
		// N?u x có giá tr? b?ng giá_tr?_2 thì do?n code trong kh?i l?nh này s? du?c th?c thi
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
