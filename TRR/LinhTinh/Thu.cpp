#include<iostream>
#include<stack>
using namespace std;
int main() {
    string s;
    stack<char> st;
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
        st.push(s[i]); //Day phan tu s[i] vao stack, c -> o ...
    }
    while(!st.empty()) { //neu stack ko rong <=> false 
        cout << st.top(); //In ra phan tu o dinh, top truy cap den ptu dinh cua stack (n)
        st.pop(); //Loai phan tu o dinh
    }
    return 0;
}
