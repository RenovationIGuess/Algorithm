#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector <int> > res;

void Reformed(int a[], int n)
{
	vector<int> part;
	for(int i = 1; i <= n; ++i)
	{
		a[i] += a[i + 1];
		part.push_back(a[i]);
	}
	res.push_back(part);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int *a = new int[n + 1];
	vector<int> part;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		part.push_back(a[i]);
	}
	res.push_back(part);
	while(--n) Reformed(a, n);
	for(int i = res.size() - 1; i >= 0; --i)
	{
		cout << "{";
		for(int j = 0; j < res[i].size() - 1; ++j)
			cout << res[i].at(j) << ", ";
		cout << res[i].at(res[i].size() - 1) << "}" << endl;
	}
	return 0;
}
