#include<iostream>
#define MAX 101
#define MINUS -1001
using namespace std;

int n;
int a[MAX][MAX];
int res;

/*
//kiem tra dung output chua
int check()
{
	//luu tong hang va cot
	int row = 0, col = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			row += a[i][j];
			col += a[j][i];
		}
		if(row != col) return 0;
	}
	return 1;
}
*/

void Try()
{
	int row[MAX] ={0}, col[MAX] = {0};
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(a[i][j] != a[j][i])
			{
				if(a[i][j] > a[j][i])
				{
					res += (a[i][j] - a[j][i]);
					a[j][i] = a[i][j];
				}
				else 
				{
					res += (a[j][i] - a[i][j]);
					a[i][j] = a[j][i];
				}
			}
		}
	}
	
	/*for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	} */
	
	int max = MINUS;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			row[i] += a[i][j];
			//col[i] += a[j][i];
		}
		//cout << row[i] << " - " << col[i] << endl;
		//cout << row[i] << endl;
		//if(row[i] > col[i])
		//{
			if(row[i] > max)
			{
				max = row[i];
			}
		//}
		/*else if(col[i] > row[i])
		{
			if(col[i] > max)
			{
				max = col[i];
			}
		}*/
	}
	//cout << max << endl;
	/*for(int i = 0; i < n; ++i)
	{
		cout << row[i] << " - " << col[i] << endl;
	} */
	
	for(int i = 0; i < n; ++i)
	{
		if(row[i] != max)
		{
			a[i][i] += (max - row[i]);
			res += (max - row[i]);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int row = 0; row < n; ++row)
			for(int col = 0; col < n; ++col)
				cin >> a[row][col];
		res = 0;
		Try();
		cout << res << endl;
		/*for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl; */
	}
	return 0;
}
