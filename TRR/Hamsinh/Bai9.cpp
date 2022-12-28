#include<iostream>
using namespace std;

int n;


string Change(string s)
{
	//string res = "0";
	for(int j = 1; j < s.size(); ++j) {
		if(s[j] == s[j - 1]) s[j] = '0';
		//res += '0';	
		else s[j] = '1';
		//res += '1';
	}
	return s;
} 

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	string s[n];
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 0; i < n; ++i) {
		cout << Change(s[i]) << endl;
	}
	return 0;
}
