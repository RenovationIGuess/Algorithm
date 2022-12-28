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
				if(st.size() == 0)
				{
					check = false;
					break;
				}
				else if(st.top() == '(') st.pop();
			}
			else if(s[i] == '}')
			{
				if(st.size() == 0)
				{
					check = false;
					break;
				}
				else if(st.top() == '{') st.pop();
			}
			else if(s[i] == ']')
			{
				if(st.size() == 0)
				{
					check = false;
					break;
				}
				else if(st.top() == '[') st.pop();
			}
		}
		if(!st.empty()) check = false;
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
