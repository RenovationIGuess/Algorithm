#include<iostream>
#include<algorithm>
using namespace std;

struct HanhDong
{
	int Si;
	int Fi;
};

HanhDong hd[1001];

bool cmp(HanhDong a, HanhDong b)
{
	return a.Fi < b.Fi;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int res = 1;
	int vitri = 0;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> hd[i].Si;
	}
	
	for(int i = 0; i < n; ++i)
	{
		cin >> hd[i].Fi;
	}
	
	sort(hd, hd + n, cmp);
	
	for(int i = 1; i < n; ++i)
	{
		if(hd[i].Si >= hd[vitri].Fi)
		{
			res++;
			vitri = i;
		}
	}
	
	cout << res << endl;
	return 0;
}
