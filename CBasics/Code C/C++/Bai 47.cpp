#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			a += i;
		}
	}
	cout << a;
	return 0;
}
