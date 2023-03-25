#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

int n, m;
vector<int> a[MAX];

int cc[MAX]; // luu dinh i thuoc tphan cc nao
int nbCC; // number of connected component

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void DFS(int u) {
    cc[u] = nbCC;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        // chua duoc tham
        if (cc[v] == 0) {
            DFS(v);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        cc[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (cc[i] == 0) {
            nbCC++;
            DFS(i);
        }
    }
}

void print() {
    for (int i = 1; i <= nbCC; ++i) {
        cout << "TP lien thong " << i << ": ";
        for (int j = 1; j <= n; ++j) {
            if (cc[j] == i) cout << j << " ";
        } cout << endl;
    }
}

int main() {
    input();
    solve();
    cout << nbCC << endl;
    return 0;
}