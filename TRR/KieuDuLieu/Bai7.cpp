#include<iostream>
#include<stack>
using namespace std;

int NP[1000]; //dung de sinh NP
bool check;

void Try(int n)
{
	int i = n - 1;
	while(i > 0 && NP[i] == 1) i--;
	if(i <= 0) 
	{
		check = true; 
	}
	else 
	{
		NP[i] = 1;
		for(int j = i + 1; j < n; ++j)
		{
			NP[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		string s;
		int k;
		int a[150] = {0};
		check = false;
		
		cin >> k >> s;
		
		for(int i = 0; i < s.size(); ++i)
		{
			a[(int)s[i]]++;
		}
		
		/*for(int i = 0; i < s.size(); ++i)
		{
			cout << a[s[i]] << " ";
		} cout << endl; */
		
		int res = 0;
		
		while(!check)
		{
			for(int i = 0; i < s.size(); ++i)
			{
				if(NP[i] == 1)
			}
		}
		
		for(int i = 0; i < s.size(); ++i)
		{
			if(i != k)
			{
				res += a[(int)s[i]]*a[(int)s[i]];
			}
		}
		
		cout << res << endl;
	}
	return 0;
}
