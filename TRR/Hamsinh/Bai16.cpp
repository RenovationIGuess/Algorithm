#include<iostream>
using namespace std;

int n, s;
bool check;
int t[100], c[100];

void Try(int i) {
	int k = i;
	//Xet tu cuoi 
	while(k > 0 && c[k] == n - i + k) k -= 1;
	//i = 1, n - i + k = n, c[1] = 1 => k = 1
	if(k == 0) check = true;
	else 
	{
		c[k] += 1;
		for(int j = k + 1; j <= i; ++j) 
		{
			c[j] = c[j - 1] + 1;
		}  
	}
}

int main() {
	//Y tuong:
	//Sinh to hop
	//Sinh to hop chap k xem tong co = so tien can ko
	//Neu == thi k la min
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) cin >> t[i];
	//Nhap cac to tien
	for(int i = 1; i <= n; ++i)
	//Xet de sinh to hop chap tu 1 -> n 
	//<=> i la so to tien
	{
		check = false;
		for(int j = 1; j <= n; ++j) 
		{
			c[j] = j; 
			//luu vi tri cua cac to tien
		}
		while(!check) 
		{
			int res = 0; //result
			for(int p = 1; p <= i; ++p)
			{
				//Neu cac to tien tu co vi tri => gia tri 
				//Tu 1 -> i
				//Neu khong thoa man thi sinh to hop
				res += t[c[p]];
			}
			if(res == s) 
			{
				cout << i;
				return 0; 
			}
			Try(i);
		}
	}
	return 0;
}
