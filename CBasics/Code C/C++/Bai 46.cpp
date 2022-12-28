#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int L = 0;
	for (int i = a; i <= b; i++) {
		L += i;
	}
	cout << L;
	return 0;
}
