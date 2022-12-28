#include<iostream>
#include<math.h>
using namespace std;

long long Chan(int hihi)
{
	return hihi*hihi;
}

long long Buon(int x, int n)
{
	if(n == 0) return 1;
	if(n % 2 == 0) return Chan(Buon(x, n/2)) % 10000;
	else return x*Chan(Buon(x, n/2)) % 10000;
}

int main()
{
	int x, n;
	cin >> x >> n;
	cout << Buon(x, n);

	return 0;
}
