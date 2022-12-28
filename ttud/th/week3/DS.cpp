#include<bits/stdc++.h>
#define N 100000

using namespace std;

int n;
// int x[N][2];
vector< pair<int, int> > x;
int last;
int res;

bool sortBySec(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

void input() {
    cin >> n;
    int a, b;
    res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x.push_back(make_pair(a, b));
    }
    sort(x.begin(), x.end(), sortBySec);
}

void solve() {
    // int vectorSize = x.size();
    int last = x.front().second;
    res++;
    for (int i = 1; i < n; ++i) {
        if (x[i].first > last) {
            res++;
            last = x[i].second;
        } else {
            if (x[i].second < last) {
                last = x[i].second;
            }
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}