#include<iostream>
using namespace std;
void a(string s) {
	cout << "Hello " << s;
}
int main() {
	string s; 
	cin >> s;
	a(s);
	return 0;
}
