#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
bool cprime(int n) {
	if (n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int n; cin >> n;
	queue<int> q;
	for(int i = 2; i <= n, i < 10; i++) {
		if(cprime(i))
		q.push(i); //=> ta co cac so nguyen to tu 0 -> n  
	}
	while(!q.empty()) {
		for(int i = 1; i <= 9; i++) {
			int k = q.front()*10 + i;
			if(k <= n && cprime(k)) {
				q.push(q.front()*10 + i); 
			}
		}
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
