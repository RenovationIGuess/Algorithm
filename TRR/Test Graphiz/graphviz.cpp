#include<iostream>
#define MAX 100
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("test.dot", "w", stdout);
	int G[MAX][MAX];
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y;
		G[x][y] = 1;
	}
	cout << "digraph test" << endl << "{" << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(G[i][j] == 1) 
				cout << " " << i << " -> " << j << ";" << endl;
		}
	} cout << "}";
	return 0;
}
