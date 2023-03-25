#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int n;
int a[MAX];
int result;

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    result = 1;
}

void solve() {
    int cur_value = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < cur_value) {
            result++;
        }
        cur_value = a[i];
    }

    cout << result << endl;
}

int main() {
    input();
    solve();
    return 0;
}