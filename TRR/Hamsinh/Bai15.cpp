#include<iostream>
using namespace std;

int t;
long long res[501];

void Try(long long s) 
{
	if(s >= 1e18) return;
	if(s % t == 0)
	{ 
		res[t] = s;
		return;
	}
	Try(s*10);
	Try(s*10 + 9);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	while(n--) {
		cin >> t;
		if(res[t])
		cout << res[t];
	}
	return 0;
}
