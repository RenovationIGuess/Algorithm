#include <bits/stdc++.h>
#define MAX (int)(1e9 + 1)
using namespace std;

int n, m;

int solve() {
  // bien check de kiem tra n + m co thoa man khong
  // neu ko thi check 2n 2m
  bool check = false;
  int sum = n + m;
  int cur_res = (int)sqrt(sum);
  if (cur_res % 2 == 0) {
    int dot_num = (cur_res*cur_res) / 2;
    if (dot_num > n || dot_num > m) {
      check = true;
    }
  } else {
    // Cho so cham le la cua so co gia tri lon hon
    // 2 gia tri duoi la so cham tren 1 hang
    int dot_odd = (cur_res - 1) / 2;
    int dot_even = dot_odd + 1;
    // cout << dot_odd << " " << dot_even << endl;
    int total_dot_larger = dot_even*dot_even + dot_odd*dot_odd;
    int total_dot_smaller = cur_res*cur_res - total_dot_larger;
    if (n < m) {
      if (total_dot_smaller > n || total_dot_larger > m) {
        check = true;
      }
    } else {
      if (total_dot_smaller > m || total_dot_larger > n) {
        check = true;
      }
    }
  }

  if (check) {
    if (n < m) {
      sum = 2*n;
    } else {
      sum = 2*m;
    }
  }
  
  return sqrt(sum);
}

int main() {
  scanf("%d%d", &n, &m);
  cout << solve() << endl;
  return 0;
}
