#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	
	cin >> t;
	
	while(t--)
	{
		string s;
		stack<char> st;
		bool check = true;
		int max = -1, cnt = 0;
		
		fflush(stdin);
		//getline(cin, s);
		//cin.ignore();
		cin >> s;
		
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '{' || s[i] == '[' || s[i] == '(')
			{
				st.push(s[i]);
			}
			else if(s[i] == ')')
			{
				if(st.top() == '(') 
				{
					st.pop();
					cnt++;
				}
				else
				{
					if(max < cnt) max = cnt;
					cnt = 0;
				}
			}
			else if(s[i] == '}')
			{
				if(st.top() == '{') 
				{
					st.pop();
					cnt++;
				}
				else
				{
					if(max < cnt) max = cnt;
					cnt = 0;
				}
			}
			else if(s[i] == ']')
			{
				if(st.top() == '[') 
				{
					st.pop();
					cnt++;
				}
				else
				{
					if(max < cnt) max = cnt;
					cnt = 0;
				}
			}
		}
		cout << max*2 << endl;
	}
	return 0;
}
