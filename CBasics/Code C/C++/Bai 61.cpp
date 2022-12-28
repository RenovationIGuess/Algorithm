#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int b = 0;
	for (int i = 0; i < n; i++) {
		b = arr[0] + arr[n - 1];
	}
	cout << b;
	return 0;
}
