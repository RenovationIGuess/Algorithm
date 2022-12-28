#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a < 0 || a > 10) {
		cout << "The score is valid";
	} else {
		cout << "The score is not valid";
	}
	return 0;
}
