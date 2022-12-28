#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int n; cin >> n;
	//so bo test
	while(n--)
	{
		int t; //so lan hoan vi 
		cin >> t >> s;
		//getline(cin, s);
		int a[100], trace; //trace de duyet tu cuoi lai
		for(int i = 1; i <= s.size(); ++i) 
		{
			a[i] = (int)(s[i - 1] - '0');
		}
		trace = s.size() - 1;
		while(trace > 0 && a[trace] >= a[trace + 1]) trace--;
		if(trace == 0) cout << "BIGGEST";
		else 
		{
			int k = s.size();
			while(a[k] <= a[trace]) k--;
			swap(a[k], a[trace]);
			int l = trace + 1, r = s.size();
			while(l < r) 
			{
				swap(a[l], a[r]);
				l++; r--;
			}
			for(int j = 1; j <= s.size(); ++j)
			{
				cout << a[j];
			} cout << endl;
		}
	}
	return 0;
}
