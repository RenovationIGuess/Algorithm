#include<iostream>
#include<algorithm>
using namespace std;

struct CV 
{
	int JobID;
	int deadline;
	int profit;
};

CV job[1001];

bool cmp(CV a, CV b)
{
	return a.profit > b.profit;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> job[i].JobID >> job[i].deadline >> job[i].profit; 
	}
	
	int res = 0;
	int res_max = 0;
	int check[1001] = {0};
	
	sort(job, job + n, cmp);
	
	for(int i = 0; i < n; ++i)
	{
		while(check[job[i].deadline] && job[i].deadline > 0) job[i].deadline--;
		if(!check[job[i].deadline] && job[i].deadline > 0)
		{
			check[job[i].deadline] = 1;
			res_max += job[i].profit;
			res++;
		}
	}
	
	cout << res << " " << res_max << endl;
	
	return 0;
}
