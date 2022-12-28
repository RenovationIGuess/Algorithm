#include<iostream>

using namespace std;

int n, m;

void Sum(int **arr)
{
	for(int i = 0; i < n; ++i)
	{
		int s = 0;
		for(int j = 0; j < m; ++j)
		{
			s += arr[i][j];
		}
		cout << s << endl;
	}
}

int main()
{
	cin >> n >> m;
	
	int **arr;
	arr = new int *[n];
	for(int i = 0; i < n; ++i)
	{
		arr[i] = new int[m];
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	Sum(arr);
	
	for(int i = 0; i < n; ++i)
	{
		delete[]arr[i];
	}
	
	delete[]arr;
	
	return 0;
}
