#include<iostream>
#include<math.h>
using namespace std;
bool check(int n) {
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	} 
	return true;
}
bool check2(int n) {
	while(n >= 10 && check(n)) {
		n /= 10;
	}
	if(n < 10 && check(n)) return true;
	return false;
}
int main() {
	int n; cin >> n;
	for(int i = 2; i <= n; i++) {
		if(check2(i)) cout << i << " ";
	}
	return 0;
}
