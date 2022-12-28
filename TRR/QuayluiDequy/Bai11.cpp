#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 1e4;

int n, s, p, posi;
vector<int> a; //luu cac so nguyen to tu 2 -> 200
vector<vector<int> > res;
vector<int> v;
int visit[200] = {0};

bool Check(int num)
{
	//if(num < 2) return false;
	for(int i = 2; i <= sqrt(num); ++i)
		if(num % i == 0) return false;
	return true;
}

void NguyenTo()
{
	for(int i = 2; i <= 200; ++i)
	{
		if(Check(i)) //&& !visit[i])
		{
			//visit[i] = 1;
			a.push_back(i);
		}
	}
}

void Try(int i, int sum)
{
	if(sum > s) return;
	if(sum == s && v.size() == n)
	{
		res.push_back(v);
		return;
	}
	for(int j = i; j < a.size(); ++j)
	{
		if(!visit[j] && sum + a[j] <= s && v.size() < n)
		{
			visit[j] = 1;
			v.push_back(a[j]);
			Try(j + 1, sum + a[j]);
			visit[j] = 0;
			v.pop_back();
		}
	}
}

void Cin()
{
	cin >> n >> p >> s;
	posi = 0; //vi tri cua p trong mang a?
	for(int i = 0; i < a.size(); ++i)
	{
		if(a[i] == p)
		{
			posi = i;
			break;
		}
	}
	for(int i = 0; i < 200; ++i) visit[i] = 0;
	v.clear();
	res.clear();
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int tests;
	cin >> tests;
	NguyenTo();
	while(tests--)
	{
		Cin();
		Try(posi, 0);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); ++i)
		{
			for(int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
