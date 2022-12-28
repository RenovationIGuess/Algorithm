#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n][n];
	vector<int> b[100];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i][j] == 1) {
				b[i + 1].push_back(j + 1);
				b[j + 1].push_back(i + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < b[i].size(); j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	/* for(int i = 0; 
	
	*/
	return 0;
}
