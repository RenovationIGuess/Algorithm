#include<iostream>
using namespace std;
int a(int n) {
	if (n == 1) return 1;
	if (n % 2 != 0) {
		return n + a(n - 1);
	} else {
		return a(n - 1);
	}
}
/* Dau tien tao diem dung cho ham de quy: n = 1 thi tra ve 1 de dung lai
- Tiep theo xet den cac dong code duoi:
=> Neu n la so le thi tra ve gia tri n + a(n - 1), luc nay ta lai goi lai ham a(int n)
khi do doan code se thuc hien nhu sau:
+) Khi goi lai ham luc nay la n - 1, neu n - 1 chia het cho 2 thi tra ve n - 1 + a(n - 2) va nhu the ta co n + (n - 1) + a(n - 2) va cu nhu the
neu n - 1 chan thi tra ve ham a(n - 2) luc do n - 2 la so le va doan code lai tiep tuc nhu the */ 
int main() {
	int n;
	cin >> n;
	cout << a(n);
	return 0;
}
