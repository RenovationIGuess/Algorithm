#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	string s;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> k >> s;
		for(int i = 0; i < s.size(); ++i)
		{
			//duyet tim phan tu lon nhat tu cuoi len
			//nhu vay khi do neu swap se nhan dc max
			//phan tu co gia tri lon nhat va o gan cuoi nhat
			//thi khi swap den nhan dc chuoi max
			int Max = s[s.size() - 1];
			int posi = s.size() - 1; 
			//vi tri de swap
			for(int j = s.size() - 1; j > i && k > 0; --j)
			{
				if(s[j] > Max) 
				{
					Max = s[j];
					posi = j;
				}
			}
			if(Max > s[i] && k > 0)
			{
				k--;
				swap(s[posi], s[i]);
			}
		}
		cout << s << endl;
	}
	return 0;
}
