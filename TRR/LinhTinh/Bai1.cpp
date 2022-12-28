#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool check(char a)
{
	return a == ' ' || a == ',';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; //so bo test
	
	cin >> t;
	cin.ignore();
	
	while(t--)
	{
		string s;
		stack<char> st;
		
		//fflush(stdin);
		getline(cin, s);
		//cin >> s;
		
		for(int i = 0; i < s.size(); ++i)
		{
			//while(s[i] != ' ' && i < s.size())
			while(!check(s[i]) && i < s.size())
			{
				st.push(s[i++]);
				//<=> st.push(s[i]); i++;
			}
			while(!st.empty())
			{
				cout << st.top();
				st.pop();
			}
			//if(s[i] == ' ') cout << s[i];
			if(check(s[i])) cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
