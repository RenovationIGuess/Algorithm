#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int t, k;
vector<vector<int> > res;
int a[100];
vector<int> v;

void Try(int i, int sum)
{
	if(sum > k) return;
	if(sum == k)
	{
		res.push_back(v);
		return;
	}
	if(sum < k)
	{
		for(int j = i; j <= t; ++j)
		{
			if(sum + a[j] <= k)
			{
				v.push_back(a[j]);
				Try(j, sum + a[j]);
				v.pop_back();
				//v.erase(a[j]);
			}
		}
	}
}

void Cin()
{
	cin >> t >> k;
	for(int i = 1; i <= t; ++i) cin >> a[i];
	sort(a + 1, a + t + 1);
	v.clear();
	res.clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		Cin();
		Try(1, 0);
		if(res.size() == 0)
		{
			cout << -1 << endl;
			continue;
		} 
		else 
		{
			for(int i = 0; i < res.size(); ++i)
			{
				cout << "[";
				for(int j = 0; j < res[i].size() - 1; ++j)
				{
					cout << res[i][j] << " ";
				} 
				cout << res[i][res[i].size() - 1] << "]" << endl;
			}
		}
	}
	return 0;
}
