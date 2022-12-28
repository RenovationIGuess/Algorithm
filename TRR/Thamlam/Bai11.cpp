#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

map<long long, int> d;
int u[50];
//18 chu so
vector<int> a;

long long res;

void Try(int i, int n)
{
	for(int j = 0; j <= 1; ++j)
	{
		u[i] = j;
		if(i == n - 1)
		{
			long long ans = 0;
			for(int k = 0; k < n; ++k)
			{
				if(u[k] == 1)
					ans = ans * 10 + a[k];
			}
			if(d[ans] && ans != 0 && res < ans)
				res = ans;
		}
		else Try(i + 1, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(long long i = 1; i <= 1e6; ++i)
	{
		d[i * i * i] = 1;
	}
	
	int t;
	
	cin >> t;
	
	while(t--)
	{
		long long n;
		cin >> n;
		a.clear();
		while(n)
		{
			a.push_back(n % 10);
			n /= 10;
		}
		reverse(a.begin(), a.end());
		res = 1;
		Try(0, a.size());
		cout << res << endl;
	}
	return 0;
}
