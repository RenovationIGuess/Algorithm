#include<iostream>
#include<vector>
#include<queue>
#define oo 1e6 + 1
using namespace std;
const int MAX = 100;


int n, m;
int a, b, c, d;
int r;

vector<pair<int, int> > t[MAX]; //luu canh va trong so - danh sach ke
int dist[MAX * MAX]; //luu khoang cach tu 1 dinh den 1 dinh - xu ly trong djikstra
int shortest[MAX][MAX]; //luu duong di ngan nhat cua cac dinh
int pre[MAX * MAX], post[MAX * MAX];

void findPath(int u, int v) {
	bool check = false; //kiem tra co duong di khong
	//Floyd algorithm
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(shortest[i][j] > shortest[i][k] + shortest[k][j])
					shortest[i][j] = shortest[i][k] + shortest[k][j];
			}
		}
	}
	//dijkstra algorithm
	for(int i = 0; i < n * MAX; ++i) {
		dist[i] = oo;
	}
	pre[u] = -1;
	dist[u] = 0;
	priority_queue<pair<int, int> > q; //Heap sort 
	q.push(make_pair(u, -dist[u]));
	while(!q.empty()) {
		int s = q.top().first;
		int l = -q.top().second;
		int x = s / n; //x = nguyen cua s / n
		int y = s % n; //y = du cua s / n
		q.pop();
		//neu co duong di 
		if(s == v) {
			check = true;
			break;
		}
		//cho tung robot chay
		
		//robot 1 chay
		for(int i = 0; i < t[x].size(); ++i) {
			int xa = t[x][i].first; //dinh ke
			int xb = t[x][i].second; //trong so canh
			if(shortest[xa][y] <= r) continue; //khoang cach ngan nhat <= r <=> ko di duoc
			int next = xa * n + y; //Diem di chuyen tiep theo
			if(dist[next] > l + xb) {
				dist[next] = l + xb;
				pre[next] = s;
				q.push(make_pair(next, -dist[next]));
			} 
		}
		
		//robot 2 chay - sau khi robot 1 ko di duoc
		for(int i = 0; i < t[y].size(); ++i) {
			int ya = t[y][i].first;
			int yb = t[y][i].second;
			if(shortest[ya][x] <= r) continue;
			int next = x * n + ya;
			if(dist[next] > l + yb) {
				dist[next] = l + yb;
				pre[next] = s;
				q.push(make_pair(next, -dist[next]));
			}
		}
	}
	if(check == true) {
		int tmp = v;
		while(tmp != u) {
			post[pre[tmp]] = tmp;
			tmp = pre[tmp];
		}
		cout << "Duong di\t" << "Khoang cach" << endl;
		while(u != v) {
			int ua = u / n;
			int ub = u % n;
			cout << ua << " " << ub << "\t\t" << shortest[ua][ub] << endl;
			u = post[u];
		} 
		int va = v / n;
		int vb = v % n;
		cout << va << " " << vb << "\t\t" << shortest[va][vb] << endl;
	} else cout << "Khong co lich di chuyen khong gay nhieu!" << endl;
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) shortest[i][j] = 0;
			else shortest[i][j] = oo;
		}
	}
	for(int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		t[x].push_back(make_pair(y, w));
		t[y].push_back(make_pair(x, w));
		shortest[x][y] = shortest[y][x] = w;
	}
	cin >> a >> b >> c >> d >> r;
	//Quy bai toan ve 1 chat diem
	int st = a * n + b; //starting
	int en = c * n + d; //end
	//Giai phap an toan trong bai nay: * 100
	findPath(st, en);
	return 0;
}
