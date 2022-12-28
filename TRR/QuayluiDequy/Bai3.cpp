#include<iostream>
#include<vector>
using namespace std;

vector<int> res;

void print(int a[], int n)
{
	cout << "{";
	for(int i = 1; i < n; ++i) 
			cout << a[i] << ", ";
	cout << a[n] << "}" << endl; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int *a = new int[n + 1];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	print(a, n);
	while(--n)
	{
		for(int i = 1; i <= n; ++i)
			a[i] += a[i + 1];
		print(a, n);
	}
	delete[]a;
	return 0;
}
