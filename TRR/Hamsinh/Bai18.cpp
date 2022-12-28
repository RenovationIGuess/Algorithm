#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int k, n;
int a[100];
int visit[100][100];
vector<int> res;

void Try(int i)
{
	for(int j = 1; j <= k; ++j)
	{
		a[i] = j;
		if(i == n)
		{
			for(int p = 1; p <= n; ++p)
			{
				res.push_back(a[p]);
			}
		} else Try(i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	Try(1);
	cout << res.size()/n;
	for(int i = 0; i < res.size(); ++i)
	{
		if(i % 2 == 0) cout << endl;
		cout << res.at(i);
	}
	return 0;
}
