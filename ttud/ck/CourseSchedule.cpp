#include <bits/stdc++.h>
#define MAX 35
using namespace std;

int n;
int Q;
int d[MAX];
deque<int> subject;

void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }
  sort(d, d + n, greater<int>());
}

void solve() {
  Q = 0;
  int first_index = 0;
  int last_index = n - 1;
  int used_subject = 0;

  while (used_subject < n) {
    
    int time_amount = 6;
    while (time_amount >= d[first_index]) {
      used_subject++;
      time_amount -= d[first_index];
      first_index++;
      if (first_index > last_index) break;
    }
    // cout << time_amount << endl;
    // cout << d[last_index] << endl;
    // DK trong if co the la first_index < last_index hoac 2 cai khac nhau?
    if (first_index < last_index) {
      while (time_amount >= d[last_index]) {
        used_subject++;
        time_amount -= d[last_index];
        last_index--;
      }
    }
    // cout << time_amount << endl;
    // cout << first_index << " " << last_index << endl;
    Q++;
  }
  cout << Q << endl;
}

int main() {
  input();
  solve();
  return 0;
}