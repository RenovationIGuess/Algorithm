#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 2;
// Tim diem khop va canh cau - Ttoan Tarjan
int n, m, CriticalEdge;
vector<int> a[N];
// bool CriticalNode[N];
int Num[N], Low[N], Time;
int visited[N];
int Parent[N];
vector<pair<int, int> > bridges;
int nbChild[N]; // Luu so dinh con cua dinh thu i
bool isArticulation[N];
int cntArticulation = 0;

// Num[i]: số thứ tự của đỉnh i khi định chiều đồ thị
// Low[i]: đỉnh con có số thứ tự Num[i] thấp nhất khi bắt đầu định chiều từ i

void input() {
  scanf("%d%d", &n, &m);
  int x, y;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
}

// void visit(int u, int p) {
//   int NumChild = 0;
//   Low[u] = Num[u] = ++Time;
//   for (int i = 0; i < int(a[u].size()); ++i) {
//     int v = a[u][i];
//     if (v != p) {
//       if (Num[v]) Low[u] = min(Low[u], Num[v]);
//       else {
//         visit(v, u);
//         ++NumChild;
//         Low[u] = min(Low[u], Num[v]);
//         if (Low[v] >= Num[v]) ++CriticalEdge;
//         if (u == p) {
//           if (NumChild >= 2) CriticalNode[u] = true;
//         } else {
//           if (Low[v] >= Num[u]) CriticalNode[u] = true;
//         }
//       }
//     }
//   }
// }

// void solve() {
//   for (int i = 1; i <= n; ++i) if (!Num[i]) visit(i, i);
//   int Count = 0;
//   for (int i = 1; i <= n; ++i) if (CriticalNode[i]) Count++;
//   cout << Count << " " << CriticalEdge << endl;
// }

void dfs(int start, int parent) {
  visited[start] = 1;
  Num[start] = Low[start] = ++Time;
  Parent[start] = parent;

  for (int i = 0; i < a[start].size(); ++i) {
    int v = a[start][i];
    if (v == parent) continue;

    if (visited[v] == 0) {
      nbChild[start]++;
      dfs(v, start);
      Low[start] = min(Low[start], Low[v]);
      if (Low[v] > Num[start]) {
        bridges.push_back({start, v});
      }
    } else {
      Low[start] = min(Low[start], Num[v]);
    }
  }
}

void printNumLow() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << Num[i] << " " << Low[i] << endl;
  }
}

void printParent() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << Parent[i] << endl;
  }
}

void countArticulation() {
  for (int i = 1; i <= n; i++) {
    if (Parent[i] == -1 && nbChild[i] > 1) {
      isArticulation[i] = true;
    }
    if (Parent[i] != -1 && Parent[Parent[i]] != -1 && Low[i] >= Num[Parent[i]]) {
      isArticulation[Parent[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (isArticulation[i]) {
      cntArticulation++;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    visited[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      dfs(i, -1);
    }
  }

  countArticulation();

  cout << cntArticulation << " " << bridges.size() << endl;
}

int main() {
  input();
  solve();
  return 0;
}