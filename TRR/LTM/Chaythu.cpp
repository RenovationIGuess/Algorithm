#include<iostream>
using namespace std;

int id = 0;
int ids[3], low[3], onstack[3];

void dfs(int u) {
	ids[u] = low[u] = id++;
	for(int i = u; i <= 3; i++) {
		if(i == u) continue;
		if(ids[i] == 0) dfs(i);
	}
}
int main() {
	
	for(int i = 1; i <= 3; i++) {
		ids[i] = low[i] = onstack[i] = 0;
	} 
	dfs(1);
	for(int i = 1; i <= 3; i++) {
		cout << i << " - " << low[i] << " - " << ids[i] << endl;
	}
	return 0;
}
