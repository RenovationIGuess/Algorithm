#include<iostream>
using namespace std;
//Ham co dau vao la con tro dang xau s <=> gia tri cua dau vao se la 1 dia chi <=> &ten
void a(string* s) {
	for (int i = 0; i < (*s).size(); i++) {
		if ((*s)[i] >= 'a' && (*s)[i] <= 'z') {
			(*s)[i] -= 32;
		}
	}
}
int main() {
	string s;
	cin >> s;
	a(&s);
	cout << s;
	return 0;
}
