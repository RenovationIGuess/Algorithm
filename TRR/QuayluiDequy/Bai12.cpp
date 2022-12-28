#include<iostream>

using namespace std;

int n, res;
int Line[100] = {0}, Column[100] = {0}, Xuoi[100] = {0}, Nguoc[100] = {0};

void Try(int i)
{
	for(int j = 1; j <= n; ++j)
	{
		if(!Line[j] && !Column[j] && !Xuoi[i + j - 1] && !Nguoc[i - j + n])
		{
			Line[j] = Column[j] = Xuoi[i + j - 1] = Nguoc[i - j + n] = 1;
			if(i == n) res++;
			else Try(i + 1);
			Line[j] = Column[j] = Xuoi[i + j - 1] = Nguoc[i - j + n] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	res = 0;
	Try(1);
	cout << res;
	return 0;
}
