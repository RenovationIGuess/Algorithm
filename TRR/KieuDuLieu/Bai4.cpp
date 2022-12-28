#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	//cin.ignore();
	
	while(t--)
	{
		string s;
		cin >> s;
		//getline(cin, s);
		stack<char> st;
		bool check;
		
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == ')')
			{
				check = true;
				char c = st.top(); st.pop();
				while(c != '(')
				{
					if(c == '+' || c == '-' || c == '*' || c == '/')
					{
						check = false;
					}
					c = st.top(); st.pop();
				}
				if(check) break;
			}
			else st.push(s[i]);
		}
		if(check) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0;
}
