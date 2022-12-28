#include<iostream>
#include<vector>
using namespace std;

int n, m;
int value[100], cost[100];
int num[100];
bool check;
vector<int> v;

void Try(int k)
{
	int i = k;
	while(i > 0 && num[i] == n - k + i) i--;
	if(i == 0) check = true;
	else {
		num[i]++;
		for(int p = i + 1; p <= k; ++p)
		{
			num[p] = num[p - 1] + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int sum = 0;
	for(int i = 1; i <= n; ++i)
		cin >> value[i] >> cost[i];
	for(int i = 1; i <= n; ++i)
	{
		check = false;
		for(int j = 1; j <= i; ++j) 
			num[j] = j;
		while(!check) {
			int res = 0, wei = 0;
			for(int j = 1; j <= i; ++j) 
				wei += cost[num[j]];
			if(wei <= m) {
				for(int j = 1; j <= i; ++j)
					res += value[num[j]];
				if(res > sum) {
					v.erase(v.begin(), v.end());
					sum = res;
					for(int j = 1; j <= i; ++j) 
						v.push_back(num[j]);
				} 
			} 
			Try(i);
		}
	}
	cout << sum << endl;
	for(int i = 0; i < v.size(); ++i) 
		cout << v.at(i) << " ";
 	return 0;
}
