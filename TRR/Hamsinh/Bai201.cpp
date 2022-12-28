#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n, s, p; 
// n - so bong hoa
// s - so may man
// p - gia hoa
int a[100]; 
// mang luu cac gia tri may man bong hoa

struct cmp 
{
	bool operator() (int a, int b) 
	{
		return a < b; 
	}
};

void Binary(int bit[], int u, int v, bool *check)
{
	//i - vi tri dang xet
	//u - vi tri xet xau - bat dau do dai
	//v - do dai xau - ket thuc
	//check - kiem tra den xau cuoi
	int i = v - 1;
	while(i > 0 && bit[i] == 1) i--;
	if(i == 0 && bit[i] == 1) *check = true;
	else 
	{
		bit[i] = 1;
		for(int j = i + 1; j < v; ++j)
		{
			bit[j] = 0;
		}
	}
						
}

bool KiemTra(map<int, int, cmp> a, int sum)
{
	map<int, int> :: iterator x;
	for(x = a.begin(); x != a.end(); ++x)
	{
		if(x->first == sum)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<int, int, cmp> sum1;
	//tong nua dau
	map<int, int, cmp> sum2;
	//tong nua sau 
	int res; 
	//ket qua tam thoi
	int mini = 1e9 + 1;
	//ket qua chinh
	
	cin >> n >> s >> p;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	if(n % 2 == 0)
	{
		int bit[100] = {0};
		// luu cac xau nhi phan
		bool check = false;
		//kiem tra
		
		while(!check)
		{
			int suma = 0, sumb = 0; 
			//luu tong nua dau - a va nua sau - b TH dang xet
			int cnt = 0;
			//dem so bong hoa ung tung TH
			
			for(int i = 0; i < n/2; ++i)
			{
				if(bit[i] == 1)
				{
					suma += a[i];
					sumb += a[n - 1 - i];
					cnt++;
				}
			}

			map<int, int> :: iterator y;
			
			if(!KiemTra(sum1, suma)) 
			{
				//cout << suma << " " << cnt << endl;
				sum1.insert(make_pair(suma, cnt));
			}
				
			else
			{
				for(y = sum1.begin(); y != sum1.end(); ++y)
				{
					if(y->first == suma && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum1.erase(y);
					}	
				}
				sum1.insert(make_pair(suma, cnt));
			}
			
			if(!KiemTra(sum2, sumb)) 
			{		
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
			else
			{
				for(y = sum2.begin(); y != sum2.end(); ++y)
				{
					if(y->first == sumb && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum2.erase(y);
					}
				}
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
			
			Binary(bit, 0, n/2, &check); 
		}
		
		map<int, int> :: iterator x;
		map<int, int> :: iterator y;

		for(x = sum1.begin(); x != sum1.end(); ++x)
		{
			if(x->first > s) continue;
			else 
			{
				if(sum2.find(s - x->first) != sum2.end())
				{
					res = 0;
					y = sum2.find(s - x->first);
					res = (x->second + y->second) * 2;
					//cout << x->first << " " << y->first << endl;
					//cout << x->second << " " << y->second << endl; 
					if(res < mini)
					{
						mini = res;
					}
				}
			}
		}
	}
	else
	{
		int bit[100] = {0};
		bool check1 = false;
		bool check2 = false;
		while(!check1)
		{
			int suma = 0, sumb = 0;
			int cnt = 0; 
			
			for(int i = 0; i < n/2; ++i)
			{
				if(bit[i] == 1)
				{
					suma += a[i];
					sumb += a[n - 1 - i];
					cnt++;
				}
			}
			
			//sum1.insert(make_pair(suma, cnt));
			//sum2.insert(make_pair(sumb, cnt));
			
			map<int, int> :: iterator y;
			
			if(!KiemTra(sum1, suma)) 
			{
				//cout << suma << " " << cnt << endl;
				sum1.insert(make_pair(suma, cnt));
			}
				
			else
			{
				for(y = sum1.begin(); y != sum1.end(); ++y)
				{
					if(y->first == suma && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum1.erase(y);
					}	
				}
				sum1.insert(make_pair(suma, cnt));
			}
			
			if(!KiemTra(sum2, sumb)) 
			{		
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
			else
			{
				for(y = sum2.begin(); y != sum2.end(); ++y)
				{
					if(y->first == sumb && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum2.erase(y);
					}
				}
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
			
			Binary(bit, 0, n/2, &check1);
		}
		
		while(!check2)
		{
			int suma = 0, sumb = 0;
			int cnt = 0;
			
			for(int i = n/2; i < n; ++i)
			{
				if(bit[i] == 1)
				{
					suma += a[i];
					sumb += a[n - 1 - i];
					cnt++;
				}
			}
			
			//sum1.insert(make_pair(suma, cnt));
			//sum2.insert(make_pair(sumb, cnt));
			
			map<int, int> :: iterator y;
			
			if(!KiemTra(sum1, suma)) 
			{
				//cout << suma << " " << cnt << endl;
				sum1.insert(make_pair(suma, cnt));
			}
				
			else
			{
				for(y = sum1.begin(); y != sum1.end(); ++y)
				{
					if(y->first == suma && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum1.erase(y);
					}	
				}
				sum1.insert(make_pair(suma, cnt));
			}
			
			if(!KiemTra(sum2, sumb)) 
			{		
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
			else
			{
				for(y = sum2.begin(); y != sum2.end(); ++y)
				{
					if(y->first == sumb && y->second > cnt)
					{
						//cout << y->first << " " << y->second << endl;
						sum2.erase(y);
					}
				}
				//cout << sumb << " " << cnt << endl;
				sum2.insert(make_pair(sumb, cnt));
			}
		
			Binary(bit, n/2, n, &check2);
		}
		
		map<int, int> :: iterator x;
		map<int, int> :: iterator y;

		for(x = sum1.begin(); x != sum1.end(); ++x)
		{
			if(x->first > s) continue;
			else 
			{
				if(sum2.find(s - x->first) != sum2.end())
				{
					res = 0;
					y = sum2.find(s - x->first);
					res = (x->second + y->second) * 2;
					//cout << x->first << " " << y->first << endl;
					//cout << x->second << " " << y->second << endl; 
					if(res < mini)
					{
						mini = res;
					}
				}
			}
		}
	}
	
	cout << mini << endl;  
	return 0;
}
