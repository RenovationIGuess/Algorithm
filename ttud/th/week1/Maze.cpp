#include<bits/stdc++.h>

using namespace std;

int n, m, r, c;
int rowNum[4] = {-1, 0, 0, 1};
int colNum[4] = {0, -1, 1, 0};

struct Coord {
	int x;
	int y;
};

struct queueNode {
	Coord pt; // pt - point
	int dist;
};

bool isValid(int row, int col) {
	return (row >= 0) && (row < n) && (col >= 0) && (col < m);
}

int BFS(int **maze, Coord src) {
	if (maze[src.x][src.y] == 1) return -1;
	bool visited[n][m];
	memset(visited, false, sizeof visited);
	visited[src.x][src.y] = true;
	queue<queueNode> q;
	queueNode s = {src, 0};
	q.push(s);
	while(!q.empty()) {
		queueNode curr = q.front();
		Coord pt = curr.pt;
		// cout << pt.x << " " << pt.y << endl;
		// If out
		if (pt.x == n - 1 || pt.x == 0 || pt.y == 0 || pt.y == m - 1) {
			// cout << pt.x << " " << pt.y << endl;
			return curr.dist + 1;
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			if (isValid(row, col) && maze[row][col] != 1 && !visited[row][col]) {
				// if (row == n - 1 || row == 0 || col == 0 || col == m - 1) {
				// 	return curr.dist + 1;
				// }
				visited[row][col] = true;
				queueNode newNode = { {row, col}, curr.dist + 1 };
				q.push(newNode);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r >> c;
	// int maze[n][m];
	int **maze = new int*[n];
	for(int i = 0; i < n; ++i) {
		maze[i] = new int[m];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> maze[i][j];
		}
	}
	Coord startPt = {r - 1, c - 1};
	int dist = BFS(maze, startPt);
	cout << dist << endl;
  return 0;
}