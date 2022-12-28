#include<bits/stdc++.h>
#define MAX 50 // vi n <= 10, m <= 30
using namespace std;

vector<int> T[MAX]; // Mang 2 chieu voi T[i] la danh sach giao vien co the nhan mon i
int n, m; // m - so giao vien, n - so bai giang
bool conflict[MAX][MAX];
int load[MAX]; // load[i] luu so mon duoc phan cong cho giao vien i 
int res; // result
int x[MAX]; // x[i] la giao vien duoc phan cong day mon i thuoc (1, n)

void input() {
    cin >> m >> n;

    for (int t = 1; t <= m; ++t) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int c; // course
            cin >> c;
            // Nhung mon giao vien t co the day
            T[c].push_back(t);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            conflict[i][j] = false;
        }
    }

    int K;
    cin >> K;
    for (int k = 1; k <= K; ++k) {
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true;
        conflict[j][i] = true;
    }
}

bool check(int t, int k) {
    for (int i = 1; i <= k - 1; ++i) {
        // Neu truoc mon thu k co mon conflict voi no va da duoc gan cho giao vien t
        if (conflict[i][k] && x[i] == t) return false; 
    }
    return true;
} 

void solve() {
    int maxLoad = 0;
    for (int t = 1; t <= n; ++t) {
        maxLoad = max(maxLoad, load[t]);
    }
    if (maxLoad < res) res = maxLoad;
}

void Try(int k) {
    for (int i = 0; i < T[k].size(); ++i) {
        int t = T[k][i]; // giao vien i co the phan cong duoc mon k
        if (check(t, k)) {
            x[k] = t; // cho mon hoc k duoc dam nhiem boi giao vien t
            load[t] += 1;
            if (k == n) solve();
            else {
                // Chua tim ra loi giai toi uu va chua het mon hoc
                if (load[t] < res) {
                    Try(k + 1);
                }
                // Neu chua het mon hoc ma > res => ko can de quy nua
            }
            load[t] -= 1; // bo gan mon hoc k cho giao vien t
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    input();
    // Khoi tao gia tri load cua cac giao vien i
    for (int t = 1; t <= m; ++t) load[t] = 0;
    res = 1e9; // Khoi tao gia tri max
    Try(1);
    cout << res << endl;
    return 0;
}