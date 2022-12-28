#include<iostream>
using namespace std;

int n, s, P;
bool check;
int a[100], posi[100]; //posi luu vi tri 
int visit[100] = {0};

void Try(int i) {
	int k = i;
	//Xet tu cuoi 
	while(k > 0 && posi[k] == n - i + k) k -= 1;
	//i = 1, n - i + k = n, c[1] = 1 => k = 1
	if(k == 0) check = true;
	else 
	{
		posi[k] += 1;
		for(int j = k + 1; j <= i; ++j) 
		{
			posi[j] = posi[j - 1] + 1;
		}  
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> P;
	bool haha = false;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
	{
		check = false;
		for(int j = 1; j <= n; ++j) 
			posi[j] = j;
		while(!check)
		{
			int res = 0; //result
			for(int p = 1; p <= i; ++p)
			{
				//Neu cac to tien tu co vi tri => gia tri 
				//Tu 1 -> i
				//Neu khong thoa man thi sinh to hop
				res += a[posi[p]];
			}
			if(res == s) 
			{
				haha = true;
				cout << i * P;
				return 0; 
			}
			Try(i);
		}
	}
	if(!haha) cout << -1 << endl;
	return 0;
}
