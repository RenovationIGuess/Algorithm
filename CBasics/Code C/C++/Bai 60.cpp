#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int b = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > b) {
			b = arr[i];
		}
	}
	cout << b;
	return 0;
}
