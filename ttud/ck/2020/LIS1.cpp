#include <bits/stdc++.h>
#define MAX (int)(1e6 + 1)
using namespace std;

int T;
int n;
int a[MAX];
deque<int> d;

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    // int v;
    // cin >> v;
    // d.push_back(v);
    cin >> a[i];
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    if (!d.empty()) {
      if (a[i] < d.back()) {  
        while (d.back() > a[i]) {
          d.pop_back();
          if (d.empty()) break;
        }
        if (d.empty()) {
          d.push_back(a[i]);
        } else if (d.back() + 1 == a[i]) {
          d.push_back(a[i]);
        }
      } else if (a[i] > d.back()) {
        if (a[i] == d.back() + 1) d.push_back(a[i]);
      }
    } else {
      d.push_back(a[i]);
    }
  }
  cout << d.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
  cin >> T;
  while (T--) {
    input();
    solve();
  }
  return 0;
}