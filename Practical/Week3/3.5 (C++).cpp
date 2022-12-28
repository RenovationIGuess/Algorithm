#include<iostream>
using namespace std;
int main() {
	cout << "Enter m and n (with m < n)" << endl;
	int m, n;
	cout << "Enter m here: ";
	cin >> m;
	cout << "Enter n here: ";
	cin >> n;
	int i = m, sum = 0;
	while(i < n) {
		sum += i;
		i++;
	}
	cout << "Your result: " << sum;
	return 0;
}
