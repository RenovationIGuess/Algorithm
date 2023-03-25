#include <bits/stdc++.h>

using namespace std;

/*
9 13
5 3 1 2 6 4 3 1 4
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8

18
*/

int n, m;
int duration[10001];
int in[10001];
//in[u] la so luong dinh vao cua u
vector<int> X[10001]; //X[u] là task sau của u
bool dd[10001];
int start[10001]; //start[i] = time of beginning a task i
void BFS() {
    queue<int> qu;

    //find the tasks that is not preceded by any other tasks.
    for (int i = 1; i<= n; i++)
    {
        if (in[i] == 0)
        {
            dd[i] = true;
            start[i] = 0;
            qu.push(i);
        }
    }

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for (int v : X[u])
        {
            in[v]--;

            //start[v] is updated when current value is smaller than new start.
            //find start time of task v reasonbly
            //start[v] = start[preceded task] + duration[that task]
            start[v] = max(start[u] + duration[u], start[v]); 

            //tìm thấy thời điểm hợp lý thời gian bắt đầu của task v sau khi duyệt hết 
            //task trước nó
            if (in[v] == 0 and dd[v] == false)
            {
                dd[v] = true;
                qu.push(v);
            }
        }
    }
    int res = -1;
    for (int i = 1; i <= n; i++){
        res = max(res, start[i] + duration[i]);
    }
    cout << res;
}

int main (){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> duration[i];
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >>u >>v;
        X[u].push_back(v);
        in[v]++;
    }
    BFS();
    return 0;
}
