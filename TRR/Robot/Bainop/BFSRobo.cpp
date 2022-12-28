#include<iostream>
#include<vector>
#include<queue>
#define oo 1e6 + 1

using namespace std;
const int MAX = 100;

int n, m;
int a, b, c, d;
int r;
bool check;

vector<int> graph[MAX]; //luu canh va trong so - danh sach ke
int dist[MAX * MAX];
int shortest[MAX][MAX]; //luu duong di ngan nhat cua cac dinh
int pre[MAX * MAX], post[MAX * MAX];


void findPath(int u, int v)
{
	check = false;
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) 
				if(shortest[i][j] > shortest[i][k] + shortest[k][j])
					shortest[i][j] = shortest[i][k] + shortest[k][j];
	for(int i = 0; i < MAX * MAX; ++i)
		dist[i] = oo;
	pre[u] = -1;
	dist[u] = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int s = q.front();
		int x = s / 100;
		int y = s % 100;
		q.pop();
		if(s == v) 
		{
			check = true;
			break;
		}
		//Cho robot 2 di truoc
		
		for(int i = 0; i < graph[y].size(); ++i)
		{
			if(shortest[x][graph[y][i]] <= r) continue;
			int next = x * 100 + graph[y][i];
			if(dist[next] == oo)
			{
				q.push(next);
				dist[next] = dist[s] + 1;
				pre[next] = s;
			}
		}
		
		for(int i = 0; i < graph[x].size(); ++i)
		{
			if(shortest[graph[x][i]][y] <= r) continue;
			int next = graph[x][i] * 100 + y;
			if(dist[next] == oo)
			{
				q.push(next);
				dist[next] = dist[s] + 1;
				pre[next] = s;
			}
		}
		/* Cho robot 1 di truoc
		for(int i = 0; i < graph[x].size(); ++i)
		{
			if(shortest[graph[x][i]][y] <= r) continue;
			int next = graph[x][i] * 100 + y;
			if(dist[next] == oo)
			{
				q.push(next);
				dist[next] = dist[s] + 1;
				pre[next] = s;
			}
		}
		
		for(int i = 0; i < graph[y].size(); ++i)
		{
			if(shortest[x][graph[y][i]] <= r) continue;
			int next = x * 100 + graph[y][i];
			if(dist[next] == oo)
			{
				q.push(next);
				dist[next] = dist[s] + 1;
				pre[next] = s;
			}
		} */
	}
	if(check == true) {
		int tmp = v;
		while(tmp != u) {
			post[pre[tmp]] = tmp;
			tmp = pre[tmp];
		}
		cout << "Duong di\t" << "Khoang cach" << endl;
		while(u != v) {
			int ua = u / 100;
			int ub = u % 100;
			cout << ua << " " << ub << "\t\t" << shortest[ua][ub] << endl;
			u = post[u];
		} 
		int va = v / 100;
		int vb = v % 100;
		cout << va << " " << vb << "\t\t" << shortest[va][vb] << endl;
	} else cout << "Khong co lich di chuyen khong gay nhieu!" << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < MAX; ++i)
		for(int j = 0; j < MAX; ++j)
			if(i == j) shortest[i][j] = 0;
			else shortest[i][j] = oo;
	for(int i = 0; i < m; ++i) 
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back(y);
		graph[y].push_back(x);
		shortest[x][y] = shortest[y][x] = w;
	}
	cin >> a >> b >> c >> d >> r;
	int st = a * 100 + b; //starting
	int en = c * 100 + d; //end
	findPath(st, en);
	return 0;
}
