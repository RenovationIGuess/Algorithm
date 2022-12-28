#include<iostream>
#include<vector>
#include<algorithm>
#define oo 1e6 + 1
using namespace std;
const int MAX = 100;

typedef struct {
	bool check;
	int cnt;
	int posi[MAX]; //luu vi tri robot tai moi thoi diem
	int visit[MAX]; //danh dau dieu kien 
	int pre[MAX];
	int post[MAX];
} Robot;

Robot robot1, robot2;

int n, m;
int a, b, c, d, r;
int shortest[MAX][MAX];
vector<int> graph[MAX];

void Floyd() 
{
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) 
				if(shortest[i][j] > shortest[i][k] + shortest[k][j])
					shortest[i][j] > shortest[i][k] + shortest[k][j];
}

bool Movable(int x, int y)
{
	//x la diem dang xet cua robot con lai
	//y la vi tri cua robot dang di
	//Neu voi moi dinh ke cua y ma 
	int count = 0;
	for(int i = 0; i < graph[x].size(); ++i)
	{
		if(shortest[graph[x][i]][y] <= r) count++;	 
	}
	if(count == graph[x].size()) return true;
	else return false;
}

int dfs

void findPath()
{
	int ting = 0;
	while(robot1.check && robot2.check)
	{
		robot1.posi[ting] = 
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for(int i = 0; i < MAX; ++i)
	{
		for(int j = 0; j < MAX; ++j)
		{
			if(i == j) shortest[i][j] = 0;
			else shortest[i][j] = oo;
		}
	}
	for(int i = 0; i < m; ++i) 
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back(y);
		graph[y].push_back(x);
		shortest[x][y] = shortest[y][x] = w;
	}
	cin >> a >> b >> c >> d >> r;
	return 0;
}
