#include<iostream>
using namespace std;
void a(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	cout << s << endl;
}
int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	a(s1);
	a(s2);
	a(s3);
	return 0;
}
