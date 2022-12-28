#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 
	int n;
	vector<int> a;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if(x != 0) a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	
	int x = 0, y = 0;
	for(int i = 0; i < a.size(); ++i)
	{
		if(i % 2 == 0) x = 10 * x + a[i];
		else y = y * 10 + a[i];
	}
	
	cout << x + y << endl;
	return 0;
}
