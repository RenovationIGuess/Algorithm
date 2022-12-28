#include<bits/stdc++.h>
using namespace std;
int main() {
	int dist[5];
	priority_queue<int> q;
	for(int i = 1; i <= 5; i++) {
		dist[i] = 5;
	}
	dist[1] = 0;
	for(int i = 1; i <= 5; i++) {
		q.push(-dist[i]);
	}
	while(!q.empty()) {
		int u = -q.top(); q.pop();
		cout << u << " ";
	}
	return 0;
}
