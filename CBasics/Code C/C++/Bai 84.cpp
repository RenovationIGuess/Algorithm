#include<iostream>
using namespace std;
int a(int arr[1000], int n) {
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			b++;
		}
	}
	return b;
}
int main() {
	int n; 
	int arr[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << a(arr, n);
	return 0;
}
