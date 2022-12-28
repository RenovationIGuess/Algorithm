#include<iostream>
#include<vector>
using namespace std;

int visit[100] ={0};
int a[100];
int t, k;
bool check;
int s; //test xem co the chia khong voi vai tro la tong moi tap con

void Try(int sum, int count)
{
	if(count == k) {
		check = true;
		return;
	}
	for(int i = 1; i <= t; ++i)
	{
		if(!visit[i]) {
			visit[i] = 1;
			if(sum == s) {
				//Neu co tap k thi de quy tim tiep xem co tiep ko
				Try(0, count + 1);
				return;
			}
			if(sum > s) return;
			//Neu sum lon hon s thi k can de quy nua
			else Try(sum + a[i], count);
		}
		visit[i] = 0;
	}
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		cin >> t >> k;
		s = 0;
		check = false;
		for(int i = 1; i <= t; ++i) cin >> a[i];
		for(int i = 1; i <= t; ++i)
			s += a[i];
		if(s % k != 0) cout << -1 << "\n";
		else {
			s /= k; 
			//Neu co the chia duoc thanh k tap con
			//thi tong moi tap con = tong phan tu mang / k
			Try(0, 0);
			if(check) cout << 1 << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
