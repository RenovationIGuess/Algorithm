#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int t;
int a[100][100];
vector<string> res;
int visit[100][100];
bool check;

void Cin()
{
	cin >> t;
	for(int i = 0; i < t; ++i) {
		for(int j = 0; j < t; ++j) {
			cin >> a[i][j];
			visit[i][j] = 0;
		}
	}	
	res.clear();
	check = false;
}

void Try(int i, int j, string s)
{
	if(a[0][0] == 0 || a[t - 1][t - 1] == 0) return;
	if(i == t - 1 && j == t - 1 && a[t - 1][t - 1])
	{
		check = true;
		res.push_back(s);
		return;
	}
	if(i > 0 && a[i - 1][j] && !visit[i][j]) {
		visit[i][j] = 1;
		Try(i - 1, j , s + "U");
		visit[i][j] = 0;
	} 
	if(j > 0 && a[i][j - 1] && !visit[i][j]) 
	{
		visit[i][j] = 1;
		Try(i, j - 1, s + "L");
		visit[i][j] = 0;
	}
	if(i < t && a[i + 1][j] && !visit[i][j]) {
		visit[i][j] = 1;
		Try(i + 1, j, s + "D");
		visit[i][j] = 0;
	} 
	if(j < t && a[i][j + 1] && !visit[i][j]) {
		visit[i][j] = 1; 
		Try(i, j + 1, s + "R");
		visit[i][j] = 0;
	}
	if(i < t && j < t && !(a[i][j + 1] && a[i + 1][j]) || i >= t || j >= t) return;
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
		Try(0, 0, "");
		if(check)
		{
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); ++i)
				cout << res.at(i) << endl;
			cout << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
