#include<iostream>
#include<queue>
#define MAX 1001
#define oo 1001 
using namespace std;
int n; //n: number of peaks
int G[MAX][MAX]; //graph
int dist[MAX];
void bfs(int s) 
{
    queue<int> Q;
    for(int v = 0; v < n; v++) {
        dist[v] = oo; 
    }
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()) 
    {
        int u = Q.front(); Q.pop();
        for(int v = 0; v < n; v++) 
            if(G[u][v] == 1 && dist[v] == oo) {
                Q.push(v);
                dist[v] = dist[u] + 1;
        	}
    }
}
int main() 
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.dot", "w", stdout);*/
    cin >> n; 
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        G[x][y] = 1;
    }
    bfs(0);
    cout << "graph bfs" << endl << "{" << endl;
    for(int i = 0; i < n; i++) {
        cout << i << " -- " << dist[i] << endl;
    }
    return 0;
}
