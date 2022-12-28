#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0 && a[i] > 0) {
			b += a[i];
		}
	}
	cout << b;
	return 0;
}
