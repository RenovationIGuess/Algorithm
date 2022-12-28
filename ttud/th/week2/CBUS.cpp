#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int n, seat; // n -> number of guests, k -> number of seats
// Guest i would go from i -> i + n
int c[2*MAX + 1][2*MAX + 1]; // distance array
int minDist; // min dist from i -> j
int res; // result
int x[MAX]; // Vi tri di qua hien tai
int x_best[MAX]; // ket qua tot nhat
bool appear[MAX]; // danh dau da di qua hay chua
int dist; // khoang cach di duoc tai thoi diem xet
int load; // so hanh khach tai thoi diem xet

void input() {
    minDist = 1e9;
    cin >> n >> seat;
    for (int i = 0; i <= 2*n; ++i) {
        for (int j = 0; j <= 2*n; ++j) {
            cin >> c[i][j];
            if (i != j && minDist > c[i][j]) 
                minDist = c[i][j];
        }
    }
}

bool check(int v, int k) {
    // Neu xe bus da di qua diem nay
    if (appear[v]) return false;
    if (v > n) {
        // Neu diem hien tai > n
        // Ma xe bus lai chua di qua diem v - n
        // => false vi muon dua khach phai dua tu i -> i + n
        if (!appear[v - n]) return false;
    } else {
        // So nguoi tren xe nhieu hon so ghe
        if (load + 1 > seat) return false;
    }
    return true;
}

void solution() {
    // Neu tinh ca luc di ve ma < res hien tai
    if (dist + c[x[2*n]][0] < res) {
        res = dist + c[x[2*n]][0];
        for (int i = 0; i <= 2*n; ++i) x_best[i] = x[i];
    }
}

void Try(int k) {
    for (int v = 1; v <= 2*n; ++v) {
        if (check(v, k)) {
            x[k] = v;
            dist += c[x[k - 1]][x[k]]; 
            // Cap nhat khoang cach da di
            // Neu diem dag xet thuoc so thu tu i cua khach
            // load + 1 - tang so nguoi tren xe
            // Nguoc lai neu diem dang xet => giam so khach 
            if (v <= n) load += 1;
            else load -= 1;
            appear[v] = true;
            if (k == 2*n) solution();
            else {
                // Neu kcach hien tai lon hon
                // toan bo cac diem con lai phai di
                // voi khoang cach ngan nhat thi de quy ko thi bo qua
                if (dist + (2*n + 1 - k)*minDist < res) {
                    Try(k + 1);
                }
            }
            // Gia su chua don khach o diem nay
            if (v <= n) load -= 1;
            else load += 1;
            appear[v] = false;
            dist -= c[x[k - 1]][x[k]];
        }
    }
}

void solve() {
    dist = 0;
    load = 0;
    res = 1e9;
    for (int i = 1; i <= 2*n; ++i) {
        appear[i] = false;
    }
    x[0] = 0; // Diem xuat phat
    Try(1); // Bat dau di tu diem 1
    cout << res << endl;
}

void print() {
    for (int i = 0; i <= 2*n; ++i) cout << x_best[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    input();
    solve();
    // print();
    return 0;
}