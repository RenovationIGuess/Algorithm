#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> a[100];
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i].size(); ++j) {
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
