#include <bits/stdc++.h>
#define N 100001
/*
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
*/

using namespace std;

struct Edge {
	int u;
	int v;
	int w;
	Edge(int _u, int _v, int _w){
		this->u = _u;
		this->v = _v;
		this->w = _w;
	}
};

int n, m;

vector<Edge> edges;
int p[N];
int r[N];
int W = 0;

void input(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		edges.push_back(Edge(u,v,w));
	}
}

void makeSet(int i){
	p[i] = i;
	r[i] = 0;
}

int findParent(int x){
	if (p[x] == x) return x;
	p[x] = findParent(p[x]);
	return p[x];
}

void unify(int u, int v){
	if (r[u] < r[v]){
		p[u] = v;
	} else if (r[u] > r[v]){
		p[v] = u;
	} else {
		p[v] = u;
		r[u]++;
	}
}

void MST(){
	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){
		return e1.w < e2.w;
	});
	
	for (int i = 1; i <= n; i++){
		makeSet(i);
	}
	
	vector<Edge> TE;
	
	for(Edge e : edges){
		int rootu = findParent(e.u);
		int rootv = findParent(e.v);
		if (rootu != rootv){
			unify(rootu, rootv);
			TE.push_back(e);
			W += e.w;
		}
	}
	
	cout << W;
}

int main(){
	input();
	MST();
	return 0;
}

