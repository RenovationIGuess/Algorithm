#include<iostream> 
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	// cho c = a = b = c, hoan doi gia tri cua a va b
	cout << "after swapping, a = " << a << ", b = " << b;
	return 0;
}
