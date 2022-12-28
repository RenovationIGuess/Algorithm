#include<iostream>
using namespace std;
int main() {
	int a[100][100];
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b += a[i][j];
		}
	}
	cout << b;
	return 0;
}
