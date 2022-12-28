#include<iostream>
#include<vector>
#include<string>
#define MAX 100

using namespace std;

int n;

int v[MAX];

vector<int> a[MAX];

bool check(int u, int c) { //Kiem tra mau co the to
	for(int i = 0; i < a[u].size(); i++) {
		if(v[a[u][i]] == c) return false;
	}
	return true; //return !(v[a[u][i]] == c);
}

int max(int c) { //Tra ve so dinh toi da co the to bang mau dang xet
	int p = 0;
	for(int i = 1; i <= n; i++) {
		if(check(i, c) && v[i] == 0) {
			v[i] = c;
			p++;
		}
	}
	return p;
}

int main() 
{
	freopen("dothi2.txt", "r", stdin);
	freopen("Tomaudothi2.dot", "w", stdout);
	int m;
	cin >> n >> m;
	for(int i = 0; i < m ; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		v[i] = 0;
	}
	int count = 0, numc = 0; //count - dem dinh da duoc to, numc - so mau <=> mau t.u
	while(count < n) {
		numc++;
		count += max(numc);
	}
	string colour[9] = {"red", "green", "blue", "white", "purple", "brown", "yellow", "black", "orange"};
	cout << "graph dothi" << endl << "{" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << "[fillcolor=" << colour[v[i] - 1] << ", style=filled];" << endl;
	}
	for(int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] >= i + 1) { //a[i][j] > i
				cout << i << " -- " << a[i][j] << ";" << endl;
			} 
		}
	}
	cout << "}";
	return 0;
}
