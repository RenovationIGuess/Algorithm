#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> res;
int letters[100] = {0};
int visit[100][100] = {0};
string s;

void Create(int i, int n)
{
	for(int j = 0; j < 26; ++j)
	{
		//Neu co ky tu X trong xau hoac ky tu X da xuat hien du lan
		if(letters[j] != 0) 
		{
			//Tai vi tri i chua xuat hien ky tu X
			if(visit[i][j] == 0)
			{
				visit[i][j] = 1;
				s[i] = (char)(j + 'A');
				letters[j]--;
			}
			if(i == n)
			{
				res.push_back(s);
			} 
			else 
			{
				Create(i + 1, n);
			}
			visit[i][j] = 0;
			letters[j]++;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	//cout << s << endl;
	//for(int i = 0; i < s.size(); ++i) cout << (int)(s[i] - 'A') << endl;
	//getline(cin, s);
	for(int i = 0; i < s.size(); ++i)
	{
		for(int j = 0; j < 26; ++j)
		{
			if((int)(s[i] - 'A') == j) {
				letters[j]++;
				break;
			}
		}
	}
	//for(int i = 0; i < 26; ++i) cout << letters[i] << endl;
	int n = s.size() - 1;
	Create(0, n);
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); ++i)
	{
		cout << res.at(i) << endl;
	}
	return 0;
}
