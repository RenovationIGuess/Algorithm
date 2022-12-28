#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n; cin >> n;
	string s;
	vector<int> a[100];
	cin.ignore();
	for(int i = 1; i <= n; i++) {
		getline(cin, s); s = s + " "; //confirm that j always < s.size()
		int num = 0, j = 0;
		while(j < s.size()) {
		if(s[j] >= '0' && s[j] <= '9') {
			num = num*10 + (int)(s[j] - '0');
		} else if(num > 0) {
			a[i].push_back(num);
			num = 0;
		}
		j++;
		}
	}
	int b[100][100];
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i].size(); j++) {
			b[i][a[i][j]] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
