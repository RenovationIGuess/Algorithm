#include<iostream>
#include<map>
#include<vector>
#include<string>
#include <fstream>
//#include "DFSandBFSA2"
#define MAX 6000
using namespace std;

map<string, int> t; //t - tree
string l[MAX]; //l - list
vector<int> a[MAX];
int n, cc;
int visited[MAX];
void explore(int u) {
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) explore(a[u][i]);
	}
}
void dfs() {
	cc = 0;
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) {
			cc++;
			explore(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream in("sgb-words.txt"); 
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); */
    string s;
    n = 0;
    //int m = 0;
    while(in >> s) {
    	++n;
    	t[s] = n;
    	l[n] = s;
	}
	for(int i = 1; i <= n; i++) {
		string u = l[i];
		for(int j = 0; j <  5; j++) {
			for(char k = 'a'; k <= 'z'; k++) {
				if(u[j] == k) {
					continue;
				}
				string tmp = u;
				tmp[j] = k;
				if(t[tmp] != 0) {
					a[i].push_back(t[tmp]);
					//m++;
				}
			}
		}
	}	
	dfs();
	cout << cc; 
	return 0;
}
