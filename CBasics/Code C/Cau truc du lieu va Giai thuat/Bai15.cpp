#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
    int cnt;
    string s;
    getline(cin, s);
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        st.push(s[i]);
        if(st.top() != s[i + 1]) {
            cout << st.top() << st.size();
            while(!st.empty()) {
            	st.pop();
        	}
        }
        
    }
    return 0;
}
