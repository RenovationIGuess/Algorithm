#include<iostream>
#include<string> 
using namespace std;

bool check = false;

void ok(string &s) {
	int i = s.size() - 1;
	while(i >= 0 && s[i] == 'B') i -= 1;
	if(i < 0) check = true;
	else {
		s[i] = 'B';
		for(int j = i + 1; j < s.size(); ++j) 
			s[j] = 'A';
	}
}

int main() {
	int n; cin >> n;
	string s = "";
	for(int i = 0; i < n; ++i) s += 'A';
	do {
		cout << s << " ";
		ok(s);
	} while(check == false);
	return 0;
}
