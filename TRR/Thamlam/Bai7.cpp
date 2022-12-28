#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n;
	
	while(n--)
	{
		string s;
		//getline(cin, s);
		cin >> s;
		int dem[1001] = {0};
		//dem so lan xuat hien cua cac ky tu
		int res = 0;
		for(int i = 0; i < s.length(); ++i)
		{
			dem[s[i]]++;
			if(res < dem[s[i]])
				res = dem[s[i]];
		}
		//tim ky tu co so lan xuat hien nhieu nhat
		//neu co the xep cho ky tu do => true nguoc lai false
		if(res <= s.length()/2 + 1 && s.length() % 2 != 0) cout << 1 << endl;
		else if(s.length() % 2 == 0 && res <= s.length() - res) cout << 1 << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}
