#include<iostream>
#include<algorithm>

using namespace std;

int n, k, s, res;
int a[100];

void Try(int i)
{
	for(int j = a[i - 1] + 1; j <= n - k + i; ++j)
	{
		a[i] = j;
		if(i == k)
		{
			int sum = 0;
			for(int p = 1; p <= i; ++p)
				sum += a[p];
			if(sum == s) res++;
		} else Try(i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	while(1)
	{
		cin >> n >> k >> s;
		res = 0;
		for(int i = 1; i <= k; ++i)
			a[i] = 0;
		if(n == 0 && k == 0 && s == 0) break;
		Try(1);
		cout << res << endl;
	}	
	return 0;
}
