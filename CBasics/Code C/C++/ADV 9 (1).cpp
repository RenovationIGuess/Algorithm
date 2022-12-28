#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int b = 0;
	for (int i = 0; i < n; i++) {
		b += arr[i];
	}
	cout << "Sum = " << b;
	delete[]arr;
	return 0;
}

