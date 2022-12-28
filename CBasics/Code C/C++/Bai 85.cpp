#include<iostream>
using namespace std;
void a(string arr[1000], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i].size() >= 3) { //ten_ham.size: do dai xau
			cout << arr[i] << " ";
		}
	}
}
int main() {
	int n; 
	string arr[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	a(arr, n);
	return 0;
}
