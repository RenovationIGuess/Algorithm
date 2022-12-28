#include<iostream>
using namespace std;

int n, k;
int a[100];

void ok(int i) {
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j) {
		a[i] = j;
		if(i == k) {
			for(int l = 1; l <= k; ++l) cout << a[l];
			cout << " ";
		} else ok(i + 1);
	}
}

int main() {
	cin >> n >> k;
	a[0] = 0;
	ok(1);
	return 0;
}
