#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	vector<int> a[100];
	cin.ignore(); //Xoa 
	for(int i = 1; i <= n; ++i) {
		getline(cin, s); s = s + " ";
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
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i].size(); j++) {
			if(a[i][j] >= i + 1) 
			cout << i << " " << a[i][j] << endl;
		}
	}
	return 0;
}
