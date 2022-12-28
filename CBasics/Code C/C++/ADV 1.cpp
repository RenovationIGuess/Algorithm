#include<iostream>
using namespace std;
int main() {
	int a = 4; //Khai bao bien a
	int *p; //Khai bao con tro P
	p = &a; //Tro con tro p tro toi bien a (do gia tri cua con tro la dia chi cua bien)
	*p = 7; //Thay doi gia tri cua con tro (*(&ten_bien) dung de lay gia tri cua dia chi cua bien, ma gia tri cua p dang = dia chi cua a)
	cout << a << endl;
	cout << (int)p << " " << (int)&a;
	return 0;
}
