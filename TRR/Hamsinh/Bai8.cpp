#include<iostream>
#include<string>
using namespace std;

string xam(string s) {
	string res = "0";
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] == s[i - 1]) res += '0';
		else res += '1';
	}
	return res;
}

int main() {
	int n; 
	cin >> n;
	string s[n];
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i) {
		cout << xam(s[i]) << endl;
	}
	return 0;
}
