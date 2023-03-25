#include <bits/stdc++.h>
#define MAX 1005
#define MOD ((int)1e9 + 7)
using namespace std;

int N, K1, K2;
int S0[MAX];
int S1[MAX];

void input() {
    scanf("%d%d%d", &N, &K1, &K2);

    for (int i = 1; i <= N; ++i) {
        S0[i] = S1[i] = 0;
    }
    S0[1] = S1[K1] = 1;
    S0[0] = 1;
}

void solve() {
    for (int i = K1 + 1; i <= N; ++i) {
        S0[i] = S1[i - 1];
        for (int j = K1; j <= K2; ++j) {
            if (i - j >= 0) {
                S1[i] += S0[i - j];
            }
        }                                                                               
    }

    int res = (S0[N] + S1[N]) % ((int)1e9 + 7);
    // int res = (S0[N] + S1[N]);
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}