#include<iostream>
using namespace std;

int visit[100];

void create(int a[], int i, int n) {
	for(int j = n; j >= 1; --j) {
		if(visit[j] == 0) {
			visit[j] = 1;
			a[i] = j;
			if(i == n - 1) {
				for(int k = 0; k < n; ++k) cout << a[k];
				cout << " ";
			} else create(a, i + 1, n);
			visit[j] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 1; i <= n; ++i) visit[i] = 0;
	create(a, 0, n);
	delete[]a;
	return 0;
}
