#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<fstream>
#include<stack>
#include<algorithm>
using namespace std;
const int MAX = 1e5 + 1;

int n;
int id = 0, scc = 0;
string l[MAX];
int G[MAX][26]; //danh so lan xuat hien cua ky tu trong tu
int ids[MAX], low[MAX], onstack[MAX]; //ktra 

map<string, int> t; //tree
vector<int> a[MAX];
stack<int> b;

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 5; j++) {
			G[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 5; j++) {
			G[i][(int)(l[i][j] - 'a')]++;
		}
	}
	//do thi co huong xet all dinh 
	for(int i = 1; i <= n; i++) {
		G[i][(int)(l[i][0] - 'a')]--; //bo di ky tu dau tien
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			int check = 1;
			for(int k = 1; k < 5; k++) {
				if(G[i][(int)(l[i][k] - 'a')] > G[j][(int)(l[i][k] - 'a')]) {
					check = 0;
					break;
				}
			}
			if(check == 1) {
				a[i].push_back(j);
			}
		}
		G[i][(int)(l[i][0] - 'a')]++;
	}
}

void dfs(int u) {
	b.push(u);
	onstack[u] = 1;
	ids[u] = low[u] = id++;
	for(int i = 0; i < a[u].size(); i++) {
		if(ids[a[u][i]] == 0) dfs(a[u][i]);
		if(onstack[a[u][i]] == 1) low[u] = min(low[u], low[a[u][i]]);
	}
	if(ids[u] == low[u]) {
		while(!b.empty()) {
			int v = b.top(); b.pop();
			onstack[v] = 0;
			low[v] = ids[u];
			if(v == u) break;
		}
		scc++;
	}
}

void tarjan(string s) {
	for(int i = 1; i <= n; i++) {
		ids[i] = low[i] = onstack[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(ids[i] == 0) dfs(i);
	}
	cout << "Number of strongly connected components: " << scc << "." << endl;
	cout << "Peak which is in the same scc with " << s << " is:" << endl;
	for(int i = 1; i <= n; i++) {
		if(i == t[s]) continue;
		if(low[i] == low[t[s]]) {
			cout << l[i] << " ";
		}
	} cout << endl;
}

int main() {
	ifstream in("sgb-words.txt");
	string s;
	n = 0;
	while(in >> s) {
		++n;
		t[s] = n;
		l[n] = s;
	} solve(); //xu li input
	string u;
	getline(cin, u);
	tarjan(u);
	return 0;
}
