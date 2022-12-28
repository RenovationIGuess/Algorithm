#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#define MAX 6000 
using namespace std;
const int oo = 1e5 + 1;
int n;
bool check = false;
int dist[MAX], prev[MAX], visited[MAX], post[MAX]; //prev - previous, post - after
map<string, int> t; //tree
string l[MAX];
vector<int> a[MAX];
void bfs(int s) {
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		dist[i] = oo;
	}
	dist[s] = 0;
	prev[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < a[u].size(); i++) {
			if(dist[a[u][i]] == oo) {
				q.push(a[u][i]);
				prev[a[u][i]] = u;
				//post[u] = a[u][i];
				dist[a[u][i]] = dist[u] + 1;
			}
		}
	}
} 
void dfs(int u, int v) {
	if(u == v) {
		check = true; 
		return;
	}
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) dfs(a[u][i], v);
	}
}
void shortest(string u, string v) {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	dfs(t[u], t[v]);
	if(check == true) {
		bfs(t[u]);
		while(t[v] != t[u]) {
			cout << l[t[v]] << " <- ";
			t[v] = prev[t[v]];
		} cout << l[t[u]];
	} else cout << "No path existed between " << u << " and " << v;
}
/*void shortest(string u, string v) {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	dfs(t[u], t[v]);
	if(check == true) {
		bfs(t[u]);
		while(t[u] != t[v] ) {
			cout << l[t[u]] << " -> ";
			t[u] = post[t[u]];
		} cout << l[t[v]];
	} else cout << "No path existed between " << u << " and " << v;
} */
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream in("sgb-words.txt"); 
	//cin.ignore();
	string u, v; cin >> u >> v;
	string s;
	n = 0;
	while(in >> s) { //push string s from file inp in
		++n;
		t[s] = n;
		l[n] = s;
	}
	for(int i = 1; i <= n; i++) { //check peaks
		string u = l[i];
		for(int j = 0; j < 5; j++) { //check string
			for(char k = 'a'; k <= 'z'; k++) { //check char
				if(u[j] == k) continue;
				string tmp = u;
				tmp[j] = k;
				if(t[tmp] != 0) {
					a[i].push_back(t[tmp]);
				}
			}
		}
	}
	shortest(u, v);
	return 0;
}
