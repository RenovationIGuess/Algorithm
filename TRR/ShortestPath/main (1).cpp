#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 3;
const int oo = 1e9;
int n,m;
int tr[N], visited[N], l[N];
int dis[N][N];
vector <pair<int, int> > a[N];
void dijsktra(int xp, int kt)
{
    priority_queue<pair<int, int> > q;
    visited[xp] = 1;
    tr[xp] = -1;
    q.push(make_pair(0, xp));
    while(!q.empty()) {
        int u = q.top().second;
        int x = u;
        int kc = -q.top().first;    // khoang cach nho nhat
        q.pop();
        if (u == kt) break;
        for(int i = 0; i < a[x].size(); i++) {
            int xt = a[x][i].first; // tu xp den duoc dinh a[x][i]
            int ts = a[x][i].second;    // tu xp den a[x][i] mat ts
            if (visited[xt] == 0)  { // chua duoc den tham
                visited[xt] = 1;    // da den tham xt
                tr[xt] = u; // truoc xt la u
                l[xt] = l[u] + ts;
                q.push(make_pair(-l[xt], xt));
            }
            else if (l[xt] > l[u] + ts) {
                l[xt] = l[u] + ts;
                tr[xt] = u;
                q.push(make_pair(-l[xt], xt));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    for(int i = 1; i <= n; i++)
    {
        memset(visited,0,sizeof(visited));
        dijsktra(1,i);
        cout << l[i] << '\n';
    }
    return 0;
}
