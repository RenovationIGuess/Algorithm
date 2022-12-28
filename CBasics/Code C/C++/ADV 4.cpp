#include<iostream>
using namespace std;
void b(int* p) {
	(*p)++;
}
int main() {
	int a;
	cin >> a;
	b(&a);
	cout << "New Value of a: " << *(&a);
	return 0;
}
