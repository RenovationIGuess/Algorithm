#include <bits/stdc++.h>

using namespace std;

string s;
int k;
deque<char> q;

void input() {
  cin >> s >> k;
}

void showdq()
{
    deque<char>::iterator it;
    for (it = q.begin(); it != q.end(); ++it)
      cout << *it << " ";
    cout << '\n';
}

void solve() {
  int string_length = s.size();
  for (int i = 0; i < string_length; ++i) {
    if (!q.empty()) {
      while (s[i] > q.back()) {
        q.pop_back();
        if (q.empty()) break;
      }
    }
    q.push_back(s[i]);
    
    // if (q.size() == k) {
    //   while (!q.empty()) {
    //     cout << q.front();
    //     q.pop_front();
    //   }
    //   break;
    // }
    if (!q.empty() && (q.size() + string_length - i - 1) == k) {
      while (!q.empty()) {
        cout << q.front();
        q.pop_front();
      }
      for (int j = i + 1; j < string_length; ++j) {
        cout << s[j];
      }
      break;
    }
  }
  cout << endl;
}

int main() {
  input();
  solve();
  return 0;
}