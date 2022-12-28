#include<iostream>
using namespace std;
int a(int n) {
	int b = 1;
	if (n == 1) return 1;
	for (int i = n; i >= 1; i--) {
		b *= i;
	}
	return b;
}
int main() {
	int n;
	cin >> n;
	cout << a(n);
	return 0;
}
