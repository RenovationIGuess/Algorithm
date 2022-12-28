#include<iostream>
using namespace std;
int a(int arr[], int n) {
	if (n == 1) return arr[0];
	int b = arr[n - 1] + a(arr, n - 1); 
	return b;
}
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Sum = " << a(arr, n);
	delete[]arr;
	return 0;
}
