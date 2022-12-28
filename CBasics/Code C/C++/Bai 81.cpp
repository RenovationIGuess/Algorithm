#include<iostream>
using namespace std;
void a(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				int c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
		}
	}
}
int main() {
	int n;
	int arr[n];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	a(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
