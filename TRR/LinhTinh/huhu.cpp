#include<iostream>
#include<string>

/*int tinhtong(string s)
{
	int sum1 = 0, sum2 = 0;
	//chan - le
	for(int i = 0; i < s.size(); ++i)
	{
		if((s[i] - '0') % 2 == 0) sum1 += (s[i] - '0');
		else sum2 += (s[i] - '0');
	}
	return sum2 - sum1;
}*/

int main()
{
	string s;
	cin >> s;
	int sum1 = 0, sum2 = 0;
	//chan - le
	for(int i = 0; i < s.size(); ++i)
	{
		if((s[i] - '0') % 2 == 0) sum1 += (s[i] - '0');
		else sum2 += (s[i] - '0');
	}
	cout << sum2 - sum1 << endl;
	//cout << tinhtong(s) << endl;
	return 0;
}
