#include <bits/stdc++.h>
#define N (int)1e6
using namespace std;

int n, k, m;
int a[N];
int res;

void input() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // init
    res = 0;
}

void solve() {
    for (int i = 0; i < n - k; ++i) {
        int cur_sum = 0;
        for (int j = i; j <= i + k - 1; ++j) {
            cur_sum += a[j];
        }
        if (cur_sum == m) res++;
    }

    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}