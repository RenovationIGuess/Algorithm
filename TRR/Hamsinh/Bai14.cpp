#include<iostream>
#include<vector>
using namespace std;

int n, k, Sum;
int c[100][100];
int visit[100];
int li[100]; //xet cot?
vector<int> v;

void make(int i) 
{
	for(int j = 1; j <= n; ++j) 
	{
		if(visit[j] == 0) 
		{
			li[i] = j; //vi tri trong hang
			visit[j] = 1;
			if(i == n) 
			{
				Sum = 0;
				for(int p = 1; p <= n; ++p) 
				{
					Sum += c[p][li[p]];
				}
				if(Sum == k)
				{
					
					for(int p = 1; p <= n; ++p)
						v.push_back(li[p]);
				}
			} else make(i + 1);
			visit[j] = 0;
		}
	}	
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> c[i][j];
		}
	} 
	make(1);
	cout << v.size()/n;
	for(int i = 0; i < v.size(); ++i)
	{
		if(i % n == 0) cout << endl;
		cout << v.at(i) << " ";
	}
	return 0;
}
