#include<iostream>
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
		
		cin >> s;
		if(s.size() % 2 == 0)
		{
			for(int i = 0; i < s.size(); ++i)
			{
				if(st.empty()) st.push(s[i]);
				else if(s[i] == ')')
				{
					if(st.top() == '(' && !st.empty()) st.pop();
					else st.push(s[i]);	
				} 
				else if(s[i] == '(')
				{
					st.push(s[i]);
				}
			}
			
			int cnt1 = 0, cnt2 = 0;
			
			while(!st.empty())
			{
				if(st.top() == '(') cnt1++;
				else cnt2++;
				st.pop(); 
			}
			cout << cnt1 << " - " << cnt2 << endl;
			int res = cnt1/2 + cnt2/2 + cnt1%2 + cnt2%2;
			cout << res << endl;
		}
		else cout << "No Way" << endl;
	}
	return 0;
}
