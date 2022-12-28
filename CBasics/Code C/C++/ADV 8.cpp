#include<iostream>
using namespace std;
int a(int *p, int n) {
	int b = p[0];
	for (int i = 0; i < n; i++) {
		if (p[i] > b) {
			b = p[i];
		}
	}
	return b;
}
int main() {
	int n;
	int arr[n];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Max value = " << a(arr, n);
	return 0;  
}
