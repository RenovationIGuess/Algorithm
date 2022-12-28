#include<iostream>
using namespace std;
int a(int n) {
	if (n == 1) return 1;
	return n * a(n - 1);
} 
int main() {
	int n;
	cin >> n;
	cout << a(n);
	return 0;
}
