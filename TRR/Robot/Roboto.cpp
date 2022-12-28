#include<iostream>
#include<algorithm>
#include<vector>
#define oo 1e6 + 1
using namespace std;

const int MAX = 100;

//Co the dung struct de luu thong tin tung robot 1
//Do phai khai bao nhieu :v
typedef struct {
	bool check;
	int cnt;
	int visit[MAX];
	int pre[MAX];
	int post[MAX];
} roboto;

int n, a, b, c, d, r;
int posi1, posi2;
int cnt1, cnt2; //So lan di chuyen it nhat cua r1, r2
int shortest[MAX][MAX];
int visit1[MAX], visit2[MAX];
int pre1[MAX], post1[MAX];
int pre2[MAX], post2[MAX];
bool check1, check2;
vector<int> graph[MAX];

void Floyd() 
{
	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j) 
			{
				if(shortest[i][j] > shortest[i][k] + shortest[k][j])
				{
					shortest[i][j] > shortest[i][k] + shortest[k][j];
				}
			}
		}
	}
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

void dfs1(int u, int v, int cnt, int y) { 
	//u - vi tri x hien tai <=> a, v - c, cnt - so lan di, y - vi tri y tai thoi diem dang xet
	//vi tri y tuy vao di x hay y truoc, tuong tu voi x
	check1 = false;
	//backtracking
	visit1[u] = 1;
	for(int i = 0; i < graph[u].size(); ++i) {
		if(!visit1[graph[u][i]]) {
			if(shortest[graph[u][i]][y] <= r) continue;
			else if(y != d && Movable(y, graph[u][i])) continue;
			else 
			{
				if(graph[u][i] == v) {
					if(cnt1 > cnt + 1) {
						pre1[graph[u][i]] = u;
						cnt1 = cnt + 1;
						check1 = true;
						//break;
						//continue;
						//return;
					}
				} else {
					pre1[graph[u][i]] = u;
					posi1 = graph[u][i];
					dfs1(graph[u][i], v, cnt + 1, y);
					//if(check == false) 
					visit1[graph[u][i]] = 0; 
					pre1[graph[u][i]] = 0;
					//back tracking
				}
			}
		}
	}
}

void dfs2(int u, int v, int cnt, int x) { 
	//u - vi tri y hien tai <=> b, v - d, cnt - so lan di, x - vi tri x tai thoi diem dang xet
	//vi tri x tuy vao di x hay y truoc, tuong tu voi y
	check2 = false;
	//backtracking
	visit2[u] = 1;
	for(int i = 0; i < graph[u].size(); ++i) {
		if(visit2[graph[u][i]] == 0) {
			if(shortest[graph[u][i]][x] <= r) continue;
			else if(x != c && Movable(x, graph[u][i])) continue;
			else 
			{
				if(graph[u][i] == v) {
					//if(!check1 && )
					if(cnt2 > cnt + 1) {
						posi2 = graph[u][i];
						cnt2 = cnt + 1;
						check2 = true;
						//break;
						//continue;
						//return;
					}
				} else {
					pre2[graph[u][i]] = u;
					posi2 = graph[u][i];
					dfs2(graph[u][i], v, cnt + 1, x);
					//if(check == false) 
					visit2[graph[u][i]] = 0; 
					pre2[graph[u][i]] = 0;
					//back tracking
				}
			}
		}
	}
}

void findPath(int robot1, int robot2) 
{
	for(int i = 0; i < MAX; ++i) 
	{
		visit1[i] = 0;
		visit2[i] = 0;
	}
	
	/*while(!check1 && !check2)
	{
		dfs1(a, c, 0, b);
		dfs2(b, d, 0, c);
	} */
	while(!check1 && !check2)
	{dfs2(b, d, 0, posi1);
	dfs1(a, c, 0, posi2);}
	//cout << check1 << " " << check2 << endl;
	/*if(check1 == true && check2 == true) 
	{
		int tmp1 = c, tmp2 = d;
		//truy vet robot 1
		while(tmp1 != a) 
		{
			post1[pre1[tmp1]] = tmp1;
			tmp1 = pre1[tmp1];
		}
		//truy vet robot 2
		while(tmp2 != b)
		{
			post2[pre2[tmp2]] = tmp2;
			tmp2 = pre2[tmp2];
		}
		
	} else cout << "Khong co duong di" << endl; */
	cout << posi1 << " " << posi2 << endl;
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
	cnt1 = oo; cnt2 = oo;
	posi1 = a; posi2 = b;
	findPath(a, b);
	return 0;
}
