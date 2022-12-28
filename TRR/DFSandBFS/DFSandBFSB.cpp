#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include <string>
#include<stack>
using namespace std;
const int MAX = 6000;
int n, c = 1, num = 0, k = 0; //number of scc
string l[MAX]; //list
map<string, int> m; //map
vector<int> a[MAX]; //G
vector<int> b[MAX]; //Gr
int visited[MAX];
int t[MAX][26]; //tree
int prev[MAX], post[MAX], p[MAX], key[MAX];
int dist[MAX], beh[MAX], aft[MAX]; //behind - peaks, after - peaks
void bfs(int s, int v) {
	queue<int> q; 
	visited[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < a[u].size(); i++) {
			if(visited[a[u][i]] == 0) {
				q.push(a[u][i]);
				visited[a[u][i]] = 1;
				beh[a[u][i]] = u;
			}
			if(a[u][i] == v) return;
		}
	}
}
void print(string v, string w) {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}	
	bfs(m[v], m[w]);
	int tmp = m[w];
	while(tmp != m[v]) {
		aft[beh[tmp]] = tmp;
		tmp = beh[tmp];
	}
	while(m[v] != m[w]) {
		cout << l[m[v]] << " -> ";
		m[v] = aft[m[v]];
	} cout << l[m[w]];
}
void previsit(int u) {
	prev[u] = c;
	c++; 
}
void postvisit(int u) {
	post[u] = c;
	c++;
}
void explore(int u) {
	previsit(u);
	visited[u] = 1;
	for(int i = 0; i < b[u].size(); i++) {
		if(visited[b[u][i]] == 0) explore(b[u][i]);
	}
	postvisit(u);
}
void dfs() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) explore(i);
	}
} 
void dfs2(int u) {
	key[u] = k;
	visited[u] = 1;
		for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) dfs2(a[u][i]);
	}
}
void scc(string u) { 
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	dfs();
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(post[i] < post[j]) {
				swap(post[i], post[j]);
				swap(p[i], p[j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[p[i]] == 0) {
			++num;
			dfs2(p[i]);
			k++;
		}
	} cout << "(a): " << num << endl;
	cout << "(b):" << endl;
	for(int i = 1; i <= n; i++) {
		if(key[i] == key[m[u]]) {
			cout << l[i] << " ";
		}
	} cout << endl;
}
void sta() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 26; j++) {
			t[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		string u = l[i];
		for(int j = 0; j < 5; j++) {
			t[i][(int)(u[j] - 'a')]++; 
		}
	}
	for(int i = 1; i <= n; i++) {
		string u = l[i];
		
		t[i][(int)(u[0] - 'a')]--;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			//int cnt = 0;
			string p = l[j];
			int check = 1;
			for(int k = 1; k < 5; k++) {
				
				if(t[i][(int)(u[k] - 'a')] > t[j][(int)(u[k] - 'a')]) {
					check = 0;
					break;
				}
			}
			if(check == 1) {
				a[i].push_back(j);
				b[j].push_back(i);	
			} 
		} 
		t[i][(int)(u[0] - 'a')]++;
	}
}
int main() {
	ifstream in("sgb-words.txt");
	freopen("inputb.txt", "r", stdin);
	freopen("outputb.txt", "w", stdout); 
	string s;
	n = 0;
	while(in >> s) {
		++n;
		m[s] = n;
		l[n] = s; 
	}
	string u, v, w; getline(cin, u);
	sta();
	scc(u);
	getline(cin, v); getline(cin, w);
	cout << "(c): " << endl;
	print(v, w);
	return 0;
}
/* if using tarjan algorithm to find strong connected components (scc):
int ids[MAX], low[MAX], onstack[MAX];
int id = 1, scc = 0; 
stack<int> c;
void dfs(int u) {
	c.push(u);
	onstack[u] = 1;
	ids[u] = low[u] = id++; //ids will help to find whether the peak is visited or not
	//now ids[u] = low[u] = 0 because after the command up there id = 1
	//after dfs recall done => low[u] = ids[u] will change = id != 0 because from the start low[u] and ids[u] = 1 (u is often 1)
	//VD: 1 -> 2 -> 3 -> 1 (no escape) => pretends that we start from 1 => ids[2] = 2, ids[3] = 3, ids[1] = 1 => ensure that  
	for(int i = 0; i < a[u].size(); i++) {
		if(ids[a[u][i]] == 0) dfs(a[u][i]);
		if(onstack[a[u][i] == 1) low[u] = min(low[a[u][i], low[u]);
	} //=> with that example => low[u] = 1;
	if(ids[u] == low[u]) {
		while(!c.empty()) {
			int v = c.top(); c.pop();
			onstack[v] = 0;
			low[v] = ids[u]; //the first element of the stack is the last goes in (3)
			if(v == u) break;
		}
		scc++;
	}
}
void tarjan(string u) {
	for(int i = 1; i <= n; i++) {
		ids[i] = 0;
		onstack[i] = 0;
		low[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(ids[i] == 0) dfs(i);
	}
	for(int i = 1; i <= n; i++)  {
		if(low[i] == low[m[u]]) {
			cout << l[i] << " ";
		}
	}
} */
