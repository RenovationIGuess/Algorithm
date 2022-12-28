#include<iostream>

using namespace std;

int huhu[10];
int k;

void Hihi(int a, int c)
{
	
	if(k == 0) return;
	k--;
	huhu[a]--;
	huhu[c]++;
}

void Play(int n, int a, int b, int c)
{
	if(k == 0) return;
	if(n == 1) Hihi(a, c);
	else 
	{
		Play(n - 1, a, c, b);
		Hihi(a, c);
		Play(n - 1, b, a, c);	
	} 
}

int main()
{
	ios_base:: sync_with_stdio(0);
	cin.tie(0);
	int n, a = 1, b = 2, c = 3;
	cin >> n >> k;
	huhu[1] = n;
	Play(n, a, b, c);
	cout << huhu[1] << " " << huhu[2] << " " << huhu[3];
	return 0;
}
