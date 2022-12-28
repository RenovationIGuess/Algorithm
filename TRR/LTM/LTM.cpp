#include<iostream>
//#include<vector>
#define MAX 500
using namespace std;
int a[MAX][MAX], b[MAX][MAX];
//vector<int> l[MAX];
int pnum; //number of peaks
int c, cc, num = 0, k = 0; //cc: connected components, n: number of scc
int pre[MAX], post[MAX];
int visited[MAX];
//int ccnum[MAX];
void prev(int v) {
	//ccnum[v] = cc;
	pre[v] = c; //c: clock
	c++;
}
void postv(int v) {
	post[v] = c;
	c++;
}
void explore(int v) {
	visited[v] = 1;
	prev(v);
	for(int u = 0; u < pnum; u++) {
		if(b[v][u] == 1) {
			if(visited[u] == 0) explore(u);
		}
	}
	postv(v);	
}
void dfs() {
	//cc = 0;
	for(int u = 0; u < pnum; u++) {
		visited[u] = 0;
	}
	for(int u = 0; u < pnum; u++) {
		if(visited[u] == 0) {
			//cc++;
			explore(u);	
		}
	}
}
void dfs2(int v) {
	visited[v] = 1;
	pre[v] = k;
	//l[num].push_back(v);
	for(int u = 0; u < pnum; u++) {
		if(a[v][u] == 1) {
			if(visited[u] == 0) dfs2(u);
		}
	}
}
int main() {
	/*freopen("inputltm.txt", "r", stdin);
	freopen("outputltm.dot", "w", stdout); */
	c = 1;
	int m; 
	cin >> pnum >> m;
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			a[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u][v] = 1;
	}
	/*for(int i = 0; i < pnum; i++) {
		cout << i << ": " << ccnum[i] << endl;
	}*/
	/*for(int u = 0; u < pnum; u++) {
		cout << u << ": " << pre[u] << " - " << post[u] << endl;
	}*/
	/*for(int i = 0; i < pnum; i++) {
		for(int j = 0; j < pnum; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	for(int i = 0; i < pnum; i++) {
		for(int j = 0; j < pnum; j++) {
			if(a[i][j] == 1) b[j][i] = 1;
		}
	}
	dfs();
	int p[pnum];
	for(int i = 0; i < pnum; i++) {
		p[i] = i;
	}
	for(int i = 0; i < pnum; i++) {
		int tmp, tmp2;
		for(int j = i + 1; j < pnum; j++) {
			if(post[i] < post[j]) {
				tmp = post[i];
				post[i] = post[j];
				post[j] = tmp;
				tmp2 = p[i];
				p[i] = p[j];
				p[j] = tmp2;
			}
		}
	}
	/*for(int i = 0; i < pnum; i++) {
		for(int j = 0; j < pnum; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < pnum; i++) {
		cout << post[i] << " ";
	} cout << endl;
	for(int i = 0; i < pnum; i++) {
		cout << p[i] << " ";
	} cout << endl; */
	for(int i = 0; i < pnum; i++) {
		visited[p[i]] = 0;
	}
	for(int i = 0; i < pnum; i++) {
		if(visited[p[i]] == 0) {
			dfs2(p[i]);
			k++;
			num++;
		} 
	} 
	cout << num << endl;
	int j = 0;
	while(j < k) {
		for(int i = 0; i < pnum; i++) {
			if(pre[i] == j) cout << i << " ";
		}
		j++;
		cout << endl;
	}
	/*for(int i = 0; i < num; i++) {
		for(int j = 0; j < l[i].size(); j++) {
			cout << l[i][j] << " ";
		}
		cout << endl;
	}*/
	/* cout << "graph ltm" << endl << "{" << endl;
	for(int i = 0; i < pnum; i++) {
		for(int j = 0; j < pnum; j++) {
			if(a[i][j] == 1) cout << i << " -- " << j << ";" << endl;
		}
	} cout << "}"; */
	return 0;
}
