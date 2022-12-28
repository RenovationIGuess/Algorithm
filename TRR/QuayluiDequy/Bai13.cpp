#include<iostream>

using namespace std;

int Max;
int Line[100] = {0}, Column[100] = {0}, Xuoi[100] = {0}, Nguoc[100] = {0};
int res[100];
int a[100][100];

void Try(int i)
{
	for(int j = 1; j <= 8; ++j)
	{
		if(!Line[j] && !Column[j] && !Xuoi[i + j - 1] && !Nguoc[i - j + 8])
		{
			Line[j] = Column[j] = Xuoi[i + j - 1] = Nguoc[i - j + 8] = 1;
			res[i] = j;
			if(i == 8) 
			{
				int sum = 0;
				for(int k = 1; k <= 8; ++k) sum += a[k][res[k]];
				if(sum > Max) Max = sum;
			}
			else Try(i + 1);
			Line[j] = Column[j] = Xuoi[i + j - 1] = Nguoc[i - j + 8] = 0;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Max = 0;
	for(int i = 1; i <= 8; ++i)
		for(int j = 1; j <= 8; ++j)
			cin >> a[i][j];
	Try(1);
	cout << Max;
	return 0;
}
