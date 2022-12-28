#include<iostream>
using namespace std;
int a(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int main() {
	int n;
	int arr[n];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << a(arr, n);
	return 0;
}
