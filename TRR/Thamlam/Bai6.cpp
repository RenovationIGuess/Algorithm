#include<iostream>
#include<queue>
using namespace std;

struct cmp
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
}; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	long long val;
	//C1: priority_queue<long long, vector<long long>, greater<long long> > q;
	//C2: priority_queue<long long, vector<long long>, cmp > q;
	priority_queue<long long> q;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> val;
		q.push(-val);
	}
	
	long long res = 0;
	while(q.size() > 1)
	{
		long long fi = -q.top(); q.pop();
		long long se = -q.top(); q.pop();
		q.push(-(fi + se));
		res += fi + se; 
	}
	
	cout << res << endl;
	return 0;
}
