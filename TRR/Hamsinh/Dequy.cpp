#include<iostream>
using namespace std;

const int MAX = 100;
int n; 
int a[MAX];
int visit[MAX];

void create(int i) {
	for(int j = 1; j <= n; ++j) {
		if(visit[j] == 0) {
			visit[j] = 1;
			a[i] = j;
			if(i == n) {
				for(int k = 1; k <= n; ++k) cout << a[k];
				cout << " "; 
			} else {
				create(i + 1);
			}
			visit[j] = 0;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		visit[i] = 0;
	}
	create(1);
	return 0;
}
