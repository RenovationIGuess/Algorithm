#include <bits/stdc++.h>
#define N 100000
using namespace std;
int n,m;
vector<int> A[N];

int visited[N];

void dfs(int src){
	visited[src] = true;
	cout << src << " ";
	for (int i = 0; i < A[src].size(); i++){
		if (!visited[A[src][i]]){
			dfs(A[src][i]);
		}
	}
}

int main(){
    cin >> n >> m;
    int a,b;
    for (int i = 1; i <= m; i++){
        scanf("%d %d",&a,&b);
        A[a].push_back(b);
        A[b].push_back(a);
        sort(A[a].begin(), A[a].end());
        sort(A[b].begin(), A[b].end());
    }
    for (int i = 1; i <= n; i++){
    	if (!visited[i])
    		dfs(i);
	}
//    for (int i = 1; i <= n; i++){
//    	cout << i << "\t";
//        for (int j = 0; j < A[i].size(); j++){
//            cout << A[i][j] << " ";
//        }
//        cout << endl;
//    }
	
}
