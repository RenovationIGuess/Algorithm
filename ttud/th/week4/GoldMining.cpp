#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int n, L1, L2;
// a is the original array
// F is the largest sum if choose from storage 1 -> i - 1
// and storage i is selected
int a[N], F[N];
deque<int> d;
int res;

void input() {
    scanf("%d%d%d", &n, &L1, &L2);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        F[i] = a[i];
    }
}

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << F[i] << " ";
    } cout << endl;
}

void solve() {
    // for (int i = L1 + 1; i <= n; ++i) {
    //     int cur_max = -10000000;
    //     if (i - L2 < 1) {
    //         for (int j = 1; j <= i - L1; ++j) {
    //             if (cur_max < F[j] + a[i]) {
    //                 cur_max = F[j] + a[i];
    //             }
    //         }
    //         F[i] = cur_max;
    //     } else {
    //         for (int j = i - L2; j <= i - L1; ++j) {
    //             if (cur_max < F[j] + a[i]) {
    //                 cur_max = F[j] + a[i];
    //             }
    //         }
    //         F[i] = cur_max;
    //     }
    // }
    deque<int>::iterator iter;

    for (int i = L1 + 1; i <= n; ++i) {
        if (!d.empty()) {
            while(F[d.front()] <= F[i - L1]) {
                d.pop_front();
                if (d.empty()) break;
            }
        }
        d.push_back(i - L1);
        if (i - L2 < 1) {
            // if (!d.empty()) {
                while(d.front() < 1) {
                    d.pop_front();
                }
                F[i] = F[d.front()] + a[i];
            // }
        } else {
            while(d.front() < i - L2) {
                d.pop_front();
            }
            F[i] = F[d.front()] + a[i];
        }
        // cout << "Loop at element " << i << endl;
        // for (iter = d.begin(); iter != d.end(); ++iter) {
        //     cout << *iter << " ";
        // } cout << endl;
    }

    // print();

    res = *max_element(F + 1, F + n + 1);
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}