#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#define oo 1e3 + 1
using namespace std;
const int MAX = 1e5 + 1;

int sizes;
bool check;
//int *p = new int[sizes];
int p[MAX];
vector<int> a[MAX];
int dist[MAX];
//std::vector<std::vector<int>> a?

bool isprime(int u) {
	for(int i = 2; i <= sqrt(u); i++) {
		if(u % i == 0) return false;
	}
	return true;
}

void prime() {
	sizes = 0;
	for(int i = 1000; i <= 9999; i++) {
		if(isprime(i)) {
			p[sizes] = i;
			sizes++;
		}
	}
	
}

bool check1(int u, int v) {
	int cnt = 0; //count
	int b = u, c = v;
	while(b != 0 && c != 0) {
		int k = b % 10;
		int z = c % 10;
		if(k != z) ++cnt;
		b /= 10; c /= 10;
	}
	return cnt == 1;
}

void solve() {
	for(int i = 0; i < sizes; i++) {
		for(int j = i + 1; j < sizes; j++) {
			if(check1(p[i], p[j])) {
				a[p[i]].push_back(p[j]);
				a[p[j]].push_back(p[i]);	
			}
		}		
	}
} 

void bfs(int u, int v) {
	check = false;
	queue<int> q;
	for(int i = 0; i < sizes; i++) {
		dist[p[i]] = oo;
	}
	dist[u] = 0;
	q.push(u);
	while(!q.empty()) {
		int s = q.front(); q.pop();
		if(s == v) {
			check = true;
			return;
		}
		for(int i = 0; i < a[s].size(); i++) {
			if(dist[a[s][i]] == oo) {
				q.push(a[s][i]);
				dist[a[s][i]] = dist[s] + 1;
			}
		}
	}
} 

void print(int v) {
	if(check == true) cout << dist[v] << endl;
	else cout << "No path!" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	prime();
	solve();
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		bfs(x, y);
		print(y);
	}
	/*prime();
	cout << size; */	
	return 0;
}
