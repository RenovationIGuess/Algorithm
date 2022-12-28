#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

void BinaryGeneration(int a[], int n, int k, bool *check) {
	int i = n - 1;
	while(i > k && a[i] == 1) i--;
	if(i == k && a[i] == 1) {
		*check = true;
	} else {
		a[i] = 1;
		for(int j = i + 1; j < n; j++) {
			a[j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; //so vector
	int u, v;
	int res;
	vector<int> x;
	vector<int> y;
	map<int, int > total1;
	map<int, int > total2;
	
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}
	cin >> u >> v;
	
	if(n % 2 == 0)
	{
		int a[100] = {0};
		res = 0;
		bool check = false;
		
		while(!check) 
		{
			int sum1 = 0, sum2 = 0; //nua dau: sum1 - x, sum2 - y
			int sum3 = 0, sum4 = 0; //nua sau: x -> y
			
			for(int i = 0; i < n/2; ++i)
			{
				if(a[i] == 1)
				{
					sum1 += x[i];
					sum2 += y[i];
					sum3 += x[x.size() - 1 - i];
					sum4 += y[y.size() - 1 - i];
				}
			}
			
			total1.insert(make_pair(sum1, sum2));
			total2.insert(make_pair(sum3, sum4));
			
			BinaryGeneration(a, n/2, 0, &check);
		}

		map<int, int > :: iterator it;
		map<int, int > :: iterator it1;
		
		for(it = total1.begin(); it != total1.end(); ++it)
		{
			if(total2.find(u - it->first) != total2.end())
			{
				it1 = total2.find(u - it->first);
				if(it->second + it1->second == v)
					res++;
			}
		}
	} 
	else
	{
		int a[100] = {0};
		res = 0;
		bool check1 = false; //nua dau
		bool check2 = false; //nua sau

		while(!check1)
		{
			int sum1 = 0, sum2 = 0; //nua dau: sum1 - x, sum2 - y
			
			for(int i = 0; i < n/2; ++i)
			{
				if(a[i] == 1) 
				{
					sum1 += x[i];
					sum2 += y[i];
				}
			}
			

			
			BinaryGeneration(a, n/2, 0, &check1);
		}
		//nua sau
		while(!check2)
		{
			int sum3 = 0, sum4 = 0; //nua sau: x -> y
			
			for(int i = n/2; i < n; ++i)
			{
				if(a[i] == 1)
				{
					sum3 += x[i];
					sum4 += y[i];
				}
			}


			
			BinaryGeneration(a, n, n/2, &check2);
		}
		
		
	}
	cout << res;
	return 0;
}
