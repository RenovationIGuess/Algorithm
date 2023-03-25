#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 1;

int n, m;
int duration[N];
int in[N];
// in[u] la so luong dinh vao cua u
vector<int> X[N]; // X[u] là task sau của u
bool dd[N];
int start[N]; // start[i] = time of beginning a task i

void BFS()
{
  queue<int> q;

  // find the tasks that is not preceded by any other tasks.
  for (int i = 1; i <= n; ++i)
  {
    if (in[i] == 0)
    {
      dd[i] = true;
      start[i] = 0;
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : X[u])
    {
      in[u]--;

      // start[v] is updated when current value is smaller than new start.
      // find start time of task v reasonably
      // start[v] = start[preceded task] + duration[that task]
      start[v] = max(start[u] + duration[u], start[v]);

      // tìm thấy thời điểm hợp lý thời gian bắt đầu của task v sau khi duyệt hết
      // task trước nó
      if (in[v] == 0 and dd[v] == false)
      {
        dd[v] = true;
        q.push(v);
      }
    }
  }
  int res = -1;
  for (int i = 1; i <= n; ++i)
  {
    res = max(res, start[i] + duration[i]);
  }
  cout << res;
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> duration[i];
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= m; i++)
  {
    int u, v;
    cin >> u >> v;
    X[u].push_back(v);
    in[v]++;
  }
  BFS();
  return 0;
}