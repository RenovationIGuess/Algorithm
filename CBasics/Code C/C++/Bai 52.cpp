#include<iostream>
using namespace std; 
int main() {
	int n;
	cin >> n;
	int a = 0, i = 1;
	while (i <= n) {
		if (n % i == 0) {
			a++;
		}
		i++;
	}
	cout << a;
}
