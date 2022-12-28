#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			b++;
		}
	}
	cout << b;
	return 0;
}
