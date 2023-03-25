#include <bits/stdc++.h>
#define N 100001
using namespace std;

int n, m;
int d[N];
vector<int> A[N];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

// Idea
// Ap dung BFS
// d[v] kcach tu dinh xuat phat den v
// d[s] = 0; thuoc x
// d[v1] = 1; thuoc y
// d[v2] = 2; d[v3] = 3;
// dinh thuoc x la so chan, dinh thuoc y la so le
// Trong qua trinh BFS ta xet dinh hien tai la v -> de loan den cac diem khac
// Neu v ke voi dinh x da duoc tham, dong thoi d[v] + d[x] la chan => return false <=> khong phai do thi 2 phia

// Pseudo code
// BFS(s)
// d[s] = 0; Q.push(s);
// while (!Q.empty()) {
//  v = Q.pop();
//  for (x in A[v]) do
//      if (d[x] > -1) then // visisted
//          if (d[v] + d[x] chan) then return false
//      else // not visited
//          Q.push(x);
//          d[x] = d[v] + 1;
// }
// return true; 

bool BFS(int s) {
    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        d[i] = -1;
    }
    d[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < A[v].size(); ++i) {
            int x = A[v][i];
            if (d[x] > -1) {
                if ((d[v] + d[x]) % 2 == 0)
                    return false;
            } else {
                Q.push(x);
                d[x] = d[v] + 1;
            }
        }
    }
    return true;
}

void solve() {
    bool check = false;
    for (int i = 1; i <= n; ++i) d[i] = -1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == -1) {
            if (BFS(i)) {
                check = true;
                cout << 1 << endl;
                break;
            }    
        }
    }
    if (!check) cout << 0 << endl;
}

int main() {
    input();
    // solve();
    cout << BFS(1) << endl;
    return 0;
}