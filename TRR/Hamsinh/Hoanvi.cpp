#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[100];
bool check;

//khoi tao
void create() { 
	for(int i = 1; i <= n; ++i) 
		a[i] = i;
}

void print() {
	for(int i = 1; i <= n; ++i) 
		{cout << a[i];}
	cout << " ";
}

void permute() {
	int i = n - 1;
	//tim vi tri ma lam mat tinh giam dan cua cau hinh
	while(i > 0 && a[i] > a[i + 1])
		i -= 1;
	if(i == 0) 
		check = true;
	else 
	{
		int k = n;
		while(a[k] < a[i]) 
			k--;
		swap(a[i], a[k]);
		int l = i + 1, r = n;
		while(l < r)  
		{
			swap(a[l], a[r]);
			l++; r--;
		} 
	}
}

int main() 
{
	cin >> n;
	check = false;
	create();
	while(check == false)
	{
		print();
		permute();
	}
	return 0;
}
