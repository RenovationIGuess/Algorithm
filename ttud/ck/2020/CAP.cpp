#include <bits/stdc++.h>
#define MAX (int)(1e9 + 1)
using namespace std;

int n, m;
map<int, int> a, b;
int res;

void input() {
  res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a[v] += 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    b[v] += 1;
    if (a[v] > 0) {
      res++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    input();
    cout << res << endl;
  }
  return 0;
}