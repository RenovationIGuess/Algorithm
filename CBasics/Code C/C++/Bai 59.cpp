#include<iostream>
using namespace std;
int main() {
	int a[10];
	int b = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		b += a[i];
	}
	cout << b;
	return 0;
}
