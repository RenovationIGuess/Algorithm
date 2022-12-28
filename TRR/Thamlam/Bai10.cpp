#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	long long tu, mau;
	
	cin >> t;
	
	while(t--)
	{
		cin >> tu >> mau;
		long long res;
		while(1)
		{
			if(mau % tu == 0)
			{
				cout << "1/" << mau / tu << endl;
				break;
			}
			else 
			{
				res = mau / tu + 1;
				cout << "1/" << res << " ";
				tu = tu * res - mau;
				mau = mau * res;
			}
		}
	}
	return 0;
}
