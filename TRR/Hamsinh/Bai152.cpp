#include<iostream>
#include<algorithm>
using namespace std;

int t, a[100], m;
long long res;
bool check;

void Try(int i) {
	for(int j = 0; j <= 1; ++j) {
		a[i] = j;
		if(i == m)
		{
			long long s = 0;
			for(int k = 1; k <= m; ++k) {
				s = s*10 + a[k];
			}
			s *= 9;
			if(s % t == 0 && s >= t) 
			{
				res = s;
				check = true;
			}
		} else Try(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		check = false;
		res = 1e18;
		cin >> t;
		m = 1;
		while(m <= 17 && check == false)
		{
			Try(1);
			m += 1;
		}
		cout << res << endl;
	}
	return 0;
}
