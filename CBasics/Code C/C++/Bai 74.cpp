#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			b++;
		}
	}
	cout << b;
	return 0;
}
