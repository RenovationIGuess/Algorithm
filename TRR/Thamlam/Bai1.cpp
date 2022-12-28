#include<iostream>
#include<string>
using namespace std;

string a, b;

string Sum()
{
	while(a.size() > b.size()) b = "0" + b;
	while(b.size() > a.size()) a = "0" + a;
	string res = "";
	int nho = 0;
	//bien nho
	int len = a.size();
	for(int i = len - 1; i >= 0; --i)
	{
		int tong = (int)(a[i] - '0') + (int) (b[i] - '0') + nho;
		res = (char)(tong % 10 + '0') + res; 
		nho = tong / 10;
	}
	if(nho > 0) return (char)(nho + '0') + res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;
	
	for(int i = 0; i < a.size(); ++i)
		if(a[i] == '6') a[i] = '5';
	for(int i = 0; i < b.size(); ++i)
		if(b[i] == '6') b[i] = '5';
	cout << Sum() << " ";
	
	for(int i = 0; i < a.size(); ++i)
		if(a[i] == '5') a[i] = '6';
	for(int i = 0; i < b.size(); ++i)
		if(b[i] == '5') b[i] = '6';
	cout << Sum() << " ";
	
	return 0;
}
