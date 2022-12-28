#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for(int i = n; i >= ; --i) {
		int tmp = n;
		cout << "(";
		while(tmp >= 0) {
			tmp -= i;
			if(tmp == 1 || tmp == 0) cout << ") ";
			else cout << i << " ";
		}
	}
	return 0;
}
