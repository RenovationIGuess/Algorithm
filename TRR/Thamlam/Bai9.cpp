#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n;
	
	while(n--)
	{
		stack<int> st;
		int s, d;
		cin >> s >> d;
		while(s > 0)
		{
			d--;
			if(s > 9)
			{
				st.push(9);
				s -= 9;
			}
			else 
			{
				st.push(s);
				break;
			}
		}
		if(d < 0) 
		{
			cout << -1 << endl;
			break;
		}
		else if(d > 0)
		{
			int x = st.top(); st.pop();
			st.push(x - 1);
			while(d > 1)
			{
				st.push(0);
				d--;
			}
			st.push(1);
		}
		while(!st.empty())
		{
			cout << st.top();
			st.pop();
		} cout << endl;
	}
	
	return 0;
}
