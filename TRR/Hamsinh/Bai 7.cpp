#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	//So ma nhi phan sinh ra duoc la 2^n
	while(n--) //<=> t > 0 
	{
		//co n lan test
		int t; 
		cin >> t;
		int k = 1; //so ma nhi phan co the co
		for(int i = 1; i <= t; ++i) k *= 2;
		string s[k + 1] ; //mang cac xau nhi phan se in
		s[1] = "0";
		s[2] = "1";
		//t.u voi n = 1 thi ma Gray (0 o dau) se la 01
		if(t > 1) 
		{
			int a = 2; //phan lay doi xung 
			//lap tu 2 do ung voi i = 1 ta da co s[1], s[2]
			for(int i = 2; i <= t; ++i) 
			{
				int l = 1; //Do dai xau
				for(int j = 1; j <= i; ++j) {
					l *= 2;
				}
				for(int j = 1; j <= a; ++j) {
					s[l - j + 1] = "1" + s[j];
					s[j] = "0" + s[j] ; 
				}
				a = l; //danh dau lai vi tri cua a
				//de tiep tuc lay doi xung
			}
		}
		for(int i = 1; i <= k; ++i) {
			cout << s[i] << " ";
		} cout << endl;
	}
	return 0;
}
