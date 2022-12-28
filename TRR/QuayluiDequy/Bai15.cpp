#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
	int n;
	int u, v;
	vector<int> x;
	vector<int> y;
	vector<int> sumx1, sumx2, sumy1, sumy2;
	int res;
	cin >> n;
	res = 0; //so ket qua - output
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
		bool check = false;
		while(!check) 
		{
			/*for(int i = 0; i < n/2; ++i) cout << a[i];
			cout << endl; */
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
			//cout << sum1 << " - " << sum2 << endl << sum3 << " - " << sum4 << endl;
			//if(sum1 == u && sum2 == v) res++;
			//if(sum3 == u && sum4 == v) res++;
			sumx1.push_back(sum1);
			sumx2.push_back(sum3);
			sumy1.push_back(sum2);
			sumy2.push_back(sum4);
			BinaryGeneration(a, n/2, 0, &check);
		}
		sort(sumx1.begin(), sumx1.end());
		sort(sumx2.begin(), sumx2.end());
		sort(sumy1.begin(), sumy1.end());
		sort(sumy2.begin(), sumy2.end());
		
		/*cout << sumx1.size() << " " << sumy1.size() << endl;
		cout << sumx2.size() << " " << sumy2.size() << endl;
		for(int i = 0; i < sumx1.size(); ++i) 
		{
			cout << sumx1.at(i) << " - " << sumy1.at(i) << endl;
			cout << sumx2.at(i) << " - " << sumy2.at(i) << endl; 
		} */
		
		//O(n^2)
		/*for(int i = 0; i < sumx1.size(); ++i)
		{
			int sumx = sumx1.at(i);
			int sumy = sumy1.at(i);
			//cout << sumx << " " << sumy << endl;
			for(int j = 0; j < sumx2.size(); ++j)
			{
				sumx += sumx2.at(j);
				sumy += sumy2.at(j);
				//cout << sumx << " " << sumy << endl;
				if(sumx == u && sumy == v) res++;
				sumx -= sumx2.at(j);
				sumy -= sumy2.at(j);
			}
		} */
		
		//O(n. xau nhat la n^2
		/*for(int i = 0; i < sumx1.size(); ++i)
		{
			int j = sumx2.size() - 1;
			while(sumx1.at(i) + sumx2.at(j) >= u) 
			{
				if(sumx1.at(i) + sumx2.at(j) == u) 
				{
					if(sumy1.at(i) + sumy2.at(j) == v) 
					{
						res++;
						break;
					}
				}
				else j--;
			}
		} */
		vector<int> :: iterator it;
		map<pair<int, int>, int > sum1;
		//map<int, int > ; 
		//nua dau
		map<pair<int, int>, int > sum2;
		//nua sau 
		
		for(int i = 0; i < sumx1.size(); ++i)
		{
			sum1[make_pair(sumx1.at(i), sumy1.at(i))]++;
			sum2[make_pair(sumx2.at(i), sumy2.at(i))]++;
		}
		
		
		/*map<int, int > sum1;
		for(it = sumx1.begin(); it != sumx1.end(); ++it)
		{
			sum1[it]++;
		} 
		map<int, int > sum2;
		for(it = sumx2.begin(); it != sumx2.end(); ++it)
		{
			sum2[it]++;
		} 
		map<int, int > sum3;
		for(it = sumy1.begin(); it != sumy1.end(); ++it)
		{
			sum3[it]++;
		} 
		map<int, int > sum4; 
		for(it = sumy2.begin(); it != sumy2.end(); ++it)
		{
			sum4[it]++;
		} */
		
		map<pair<int, int>, int > :: iterator it1;
		map<pair<int, int>, int > :: iterator it2;
		
		for(it1 = sum1.begin(); it1 != sum1.end(); ++it1)
		{
			if(it->first.first)
			{
				
			}
		}
	} 
	else
	{
		int a[100] = {0};
		bool check1 = false; //nua dau
		bool check2 = false; //nua sau
		//nua dau
		while(!check1)
		{
			//for(int i = 0; i < n/2; ++i) cout << a[i];
			//cout << endl;
			int sum1 = 0, sum2 = 0; //nua dau: sum1 - x, sum2 - y
			for(int i = 0; i < n/2; ++i)
			{
				if(a[i] == 1) 
				{
					sum1 += x[i];
					sum2 += y[i];
				}
			}
			//if(sum1 == u && sum2 == v) res++;
			sumx1.push_back(sum1);
			sumy1.push_back(sum2);
			BinaryGeneration(a, n/2, 0, &check1);
		}
		//nua sau
		while(!check2)
		{
			//for(int i = n/2; i < n; ++i) cout << a[i];
			//cout << endl;
			int sum3 = 0, sum4 = 0; //nua sau: x -> y
			for(int i = n/2; i < n; ++i)
			{
				if(a[i] == 1)
				{
					sum3 += x[i];
					sum4 += y[i];
				}
			}
			//if(sum3 == u && sum4 == v) res++;
			sumx2.push_back(sum3);
			sumy2.push_back(sum4);
			BinaryGeneration(a, n, n/2, &check2);
		}
		sort(sumx1.begin(), sumx1.end());
		sort(sumx2.begin(), sumx2.end());
		sort(sumy1.begin(), sumy1.end());
		sort(sumy2.begin(), sumy2.end());
		
		/*vector<int> part1, part2; //luu tong x - y
		for(int i = 0; i < sumx1.size(); ++i)
		{
			part1.push_back(sumx1.at(i));
			part2.push_back(sumy1.at(i));
		}
		for(int j = 0; j < sumx2.size(); ++j)
		{
				sumx += sumx2.at(j);
				sumy += sumy2.at(j);
				if(sumx == u && sumy == v) res++;
				sumx -= sumx2.at(j);
				sumy -= sumy2.at(j);
			} */
			
		/*for(int i = 0; i < sumx1.size(); ++i)
		{
			int j = sumx2.size() - 1;
			while(sumx1.at(i) + sumx2.at(j) >= u) 
			{
				if(sumx1.at(i) + sumx2.at(j) == u) 
				{
					if(sumy1.at(i) + sumy2.at(j) == v) 
					{
						res++;
						break;
					}
				}
				else j--;
			}
		} */
		
	}
	cout << res;
	return 0;
}




