#include<bits/stdc++.h>
using namespace std;

long long n, m;

void input(){
	cin >> n >> m;
}

int checkSoChinhPhuong(long long k){
	int sqr = sqrt(k);
	if(sqr*sqr == k){
		return 1;
	}else{
		return 0;
	}
}

void solve(){
	long long k = min(n, m);
	for (long long i = k; i >= 1; i--){
		//cout << i << " ";
		if (checkSoChinhPhuong(2*i + 1) == 1 && n != m){
			cout << (int)sqrt(2*i+1);
			return;
		}
		else if (checkSoChinhPhuong(2*i) == 1){
			cout << (int)sqrt(2*i);
			return;
		}
		else if (checkSoChinhPhuong(2*i-1) == 1){
			cout << (int)sqrt(2*i-1);
			return;
		}
		else continue;
	}
}

int main(){
	input();
	solve();
	return 0;
}
