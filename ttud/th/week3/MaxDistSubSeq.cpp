#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int t;
int N, C;
int x[MAX];

bool check(int distance) {
    int numberOfElements = 1;
    int i = 0; 
    int j = 1;
    while (i < N - 1) {
        while (j < N && x[j] - x[i] < distance) ++j;
        if (j < N) numberOfElements++;
        if (numberOfElements >= C) return true;
        i = j;
        j++;
    }
    return false;
}

int solve() {
    int l = 0;
    int r = x[N - 1] - x[0];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
        // cout << "Left: " << l << "; Right: " << r << endl;
    }
    return r;
}

void input() {
    cin >> t;
    while(t--) {
        cin >> N >> C;
        for (int i = 0; i < N; ++i) {
            cin >> x[i];
        }
        sort(x, x + N);
        cout << solve() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    return 0;
}