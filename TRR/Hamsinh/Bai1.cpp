#include<iostream>
#include<string>
using namespace std;

string next(string s) {
	int n = s.size() - 1;
	int i = n;
	while(i > 0 && s[i] == '1') i -= 1;
	if(i == 0 && s[i] == '1') {
		for(int k = 0; k <= n; ++k) {
			s[k] = '0';
		}	
	} else {
		s[i] = '1';
		for(int j = i + 1; j <= n; ++j) {
			s[j] = '0';
		}
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i) {
		cout << next(s[i]) << endl;
	}
	return 0;
}
