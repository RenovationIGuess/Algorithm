#include<bits/stdc++.h>
using namespace std;
int kt;
int kiemtra(int a[1000][2], int n);
void prufer(int a[1000][2], int n);
int main() {
	kt = 0;
	int n; cin >> n;
	int a[n][2];
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	prufer(a, n);
	return 0;
}
void prufer(int a[1000][2], int n) {
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == kiemtra(a, n)) {
			kt++;
			check = true;
			cout << a[i][1] << " ";
			a[i][0] = 0;
			a[i][1] = 0;
			break;
		}
		if (a[i][1] == kiemtra(a, n)) {
			kt++;
			check = true;
			cout << a[i][0] <<" ";
			a[i][0] = 0;
			a[i][1] = 0;
			break;
		}
	}
	if (check = false || kt == n - 1) return; //Thoat khoi chuong trinh
	prufer(a, n); 
}
int kiemtra(int a[1000][2], int n) {
	int cnt = 0, tmp = 0;
	do {
		cnt = 0;
		tmp++;
		for (int i = 0; i < n; i++) {
			if (a[i][0] == tmp) cnt++;
			if (a[i][1] == tmp) cnt++;
		}
	} while (cnt != 1);
	return tmp;
}
/* Khi chay vong do - while => tmp luon = 1 de loai di dinh co nhan 0
- Khi vong lap chay 

