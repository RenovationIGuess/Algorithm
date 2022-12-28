#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct vt
{
	int f, l;
	//first - last	
};

bool cmp(vt a, vt b)
{
	return a.f < b.f;	
}

string s;
vector<string> res;
vector<vt> a;
int NP[100];

void Try(int i, int n)
{
	for(int j = 0; j <= 1; ++j)
	{
		NP[i] = j;
		if(i == n - 1)
		{
			int cnt = -1;
			//dem cap mo ngoac thu bnh
			int check[205] = {0};
			//danh dau cap mo ngoac
			
			for(int p = 0; p < s.size(); ++p)
			{
				if(s[p] == '(' && NP[++cnt] == 0)
				{
					check[a[cnt].f] = check[a[cnt].l] = 1;
					//da su dung
				}
			}
			//Neu co cap ngoac bi bo di (da bi danh dau)
			if(cnt >= 0)
			{
				string str = "";
				for(int i = 0; i < s.size(); ++i)
				{
					if(check[i] == 0) str += s[i];
				}
				res.push_back(str);
			}
		}
		else Try(i + 1, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	stack<int> st;
	
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '(')
		{
			st.push(i);
		}
		else if(s[i] == ')')
		{
			//int n = a.size();
			vt tmp;
			tmp.f = st.top();
			tmp.l = i;
			a.push_back(tmp);
			st.pop();
		}
	}
	
	sort(a.begin(), a.end(), cmp);
	//sx cac cap ngoac tu ngoai vao trong
	
	Try(0, a.size());
	
	sort(res.begin(), res.end());
	//sx theo thu tu tu dien
	
	vector<string> ans;
	
	for(int i = 0; i < res.size(); ++i)
	{
		if(res[i] == s) continue;
		//if(strcpy(s, res[i]) continue;
		if(ans.size() == 0) ans.push_back(res[i]);
		else if(res[i] != ans[ans.size() - 1]) ans.push_back(res[i]);
	}
	
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
		
	return 0;
}
