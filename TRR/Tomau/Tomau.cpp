//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#define MAX 1001
#define for(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
int n, m;
int a[MAX][MAX];
int v[MAX];
bool check(int d, int c) {	//colour, dinh	 
	for(i, 1, n) { //xet dinh
		if (a[d][i] == 1 && v[i] == c) return false;   
	}
	return true;
}
int max(int c) {
	int p = 0; //peaks
	for(i, 1, n) {
		if (check(i, c) && v[i] == 0) {
			v[i] = c;
			p++;
		}
	}
	return p;
}
int main() {
	freopen("dothi.txt", "r", stdin);
	freopen("Tomaudothi.dot", "w", stdout);
	cin >> n >> m;
	for (i, 1, m) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for(i, 1, n) v[i] = 0;
	int count = 0;
	int numc = 0; //number of colours
	while (count < n) {
		numc++; 	
		count += max(numc);
	}
	string colour[9] = {"red", "green", "blue", "white", "purple", "brown", "yellow", "black", "orange"};
	cout << "graph dothi" << endl << "{" << endl;
	for (i, 1, n) {
		cout << i << "[fillcolor=" << colour[v[i] - 1] << ", style=filled];" << endl;
	}
	for(i , 1, n) {
		for (j, i + 1, n) {
			if (a[i][j] == 1) {
				cout << i << " -- " << j << ";" << endl;
			} 
		}
	}
	cout << "}";
	return 0;
}

