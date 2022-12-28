#include<iostream>
using namespace std;

int t, k;
int a[100];

void make(int i) {
	for(int j = 0; j <= 1; ++j) {
		a[i] = j;
		if(i == t)
		{
			int cnt = 0; //dem so phan tu = 1;
			for(int l = 1; l <= t; ++l) {
				if(a[l] == 1) cnt++;
			}
			if(cnt == k) {
				for(int l = 1; l <= t; ++l) {
					cout << a[l];
				} cout << endl;
			} 
		} else make(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; //so bo test
	cin >> n; 
	while(n--) {
		cin >> t >> k;
		make(1);
	}
	return 0;
}
