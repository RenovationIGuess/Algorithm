#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		int t, k;
		cin >> t >> k;
		//t - so linh, k - so chi so linh
		int a[100]; //luu trang thai dau tien
		//static visit[100]; //kiem tra co bi goi 0
		int visit[100] = {0};
		//for(int i = 1; i <= k; ++i) visit[i] = 0;
		for(int i = 1; i <= k; ++i) 
		{
			cin >> a[i];
			visit[a[i]] = 1;
		}
		//Sinh to hop
		int i = k;
		while(i > 0 && a[i] == t - k + i) i--;
		if(i == 0) cout << k;
		else 
		{
			a[i] += 1;
			for(int j = i + 1; j <= k; ++j) {
				a[j] = a[j - 1] + 1;
			}
			for(int j = 1; j <= k; ++j) {
				visit[a[j]] = 0;
			}
			//sau khi xet to hop xog
			//reset visit cua a[j: 1 -> k] = 0
			//duyet tu 1 -> k neu visit[j] = 1 chung to no 
			//duoc nghi do ko xet
			int res = 0; //so nguoi nghi
			for(int p = 1; p <= 39; ++p) 
				if(visit[p]) res++;
				//cout << visit[a[p]] << " "; 
			cout << res << endl;
		} 
	}
	return 0;
}
