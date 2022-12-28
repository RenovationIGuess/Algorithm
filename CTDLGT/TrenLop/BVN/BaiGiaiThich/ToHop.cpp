#include<iostream>
#define MAX 1001
using namespace std;

string s;
//luu so ban dau nhap vao
int a[MAX];
int n, cnt;
int check[MAX] = {0};
//luu cac to hop
int b[MAX];

//convert
void Cvt()
{
	for(int i = 0; i < s.size(); ++i)
	{
		a[i + 1] = s[i] -'0';
	}
}

void print()
{
	for(int i = 1; i <= n; ++i)
	{
		if(check[i] != 0)
			cout << a[i];
	}
	cout << endl;
}

//rs - reset
void rs()
{
	for(int i = 1; i <= n; ++i)
	{
		check[i] = 0;
	}
}

//p - vi tri (position), k - to hop chap k
void Try(int p, int k, int value)
{
	for(int i = p; i <= n - k + p; ++i)
	{
		if(!check[i])
		{
			if(value > i) continue;
			check[i] = 1;
			if(p == k)
			{
				print();
			}
			else Try(p + 1, k, i);
			check[i] = 0;
		}
	}
}

/*void print2(int k)
{
	for(int i = 1; i <= k; ++i)
	{
		cout << a[i];
	} cout << endl;
}*/

/*void Try(int p, int k)
{
	for(int i = a[p - 1] + 1; i <= n - k + p; ++i)
	{
		a[p] = i;
		if(p == k)
		{
			print2(k);
		}
		else Try(p + 1, k);
	}
} */

int main()
{
	cout << "Nhap sau: ";
	cin >> s;
	n = s.size();
	Cvt();
	cnt = 0;
	for(int k = 1; k <= n; ++k)
	{
		cout << "\nCac to hop chap " << k << " cua " << n << ":" << endl;
		//sinh to hop
		Try(1, k, 1);
		//rs();
	}
	return 0;
}
