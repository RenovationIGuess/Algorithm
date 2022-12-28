#include<iostream>
using namespace std;
int a(int arr[1000], int n) {
	int b = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > b) {
			b = arr[i];
		}
	}
	return b;
}
int main() {
	int n1, n2;
	int arr1[1000], arr2[1000];
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	cout << a(arr1, n1) << " " << a(arr2, n2);
	return 0;
}
