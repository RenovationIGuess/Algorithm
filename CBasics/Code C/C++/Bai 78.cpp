#include<iostream>
using namespace std;
void a() {
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 5 != 0)  {
			cout << i << " ";
		}
	}
}
int main() {
	a();
	return 0;
}

