#include<bits/stdc++.h>

using namespace std;

int n, m;

int maxHist(int row[]) {
    stack<int> res;
    int topValue; // Top of stack
    int maxArea = 0; // Initialize max area in current row
    int area = 0; // Initialize area with current top
    int i = 0; // Use to loop through all rows
    while (i < n) {
        if (res.empty() || row[res.top()] <= row[i]) res.push(i++);
        else {
            topValue = row[res.top()];
            res.pop();
            area = topValue * i;

            if (!res.empty()) {
                area = topValue * (i - res.top() - 1);
            }
            maxArea = max(area, maxArea);
        }
    }

    while (!res.empty()) {
        topValue = row[res.top()];
        res.pop();
        area = topValue * i;
        if (!res.empty()) {
            area = topValue * (i - res.top() - 1);
        }
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int maxRect(int **rect) {
    int res = maxHist(rect[0]);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rect[i][j] == 1) rect[i][j] += rect[i - 1][j];
        }
        res = max(res, maxHist(rect[i]));
    }

    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	// int maze[n][m];
	int **rect = new int*[n];
	for(int i = 0; i < n; ++i) {
		rect[i] = new int[m];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> rect[i][j];
		}
	}
	cout << maxRect(rect) << endl;
    return 0;
}