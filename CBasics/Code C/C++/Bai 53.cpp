#include<iostream> 
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int c = 1;
	while (b > 0) {
		c *= a;
		b--;
	}
	cout << c;
}
