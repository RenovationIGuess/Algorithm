#include<iostream>
#include<queue>
#define MAX 101
#define oo 1000 // <=> vo cung (oo) = 1000
using namespace std;
int n = 6; //So dinh
int preve[MAX]; // prev[u] = v <=> dinh truoc u trong duong di la v
int G[MAX][MAX] = {
//	S	A	B	C	D	E	
	{0, 1, 0, 1, 1, 1}, //S
	{1, 0, 1, 0, 0 ,0},//A
	{0, 1, 0, 1, 0, 0}, //B
	{1, 0, 1, 0, 0 ,0}, //C
	{1, 0, 0, 0, 0, 1}, //D
	{1, 0, 0, 0, 1, 0} //E
};
int dist[MAX]; //= {0}; //Gan tat ca = 0 (C++)
void bfs(int s) 
{
	queue<int> Q; //Khai bao hang doi kieu int ten Q
	for(int u = 0; u < n; u++) {
		dist[u] = oo; //y noi k co duong di tu s -> u
	}
	preve[s] = -1;
	dist[s] = 0;
	Q.push(s); //Cho s vao queue
	while(!Q.empty()) {
		int u = Q.front(); //Lay phan tu o dau hang doi, o day chinh la s
		Q.pop(); //Loai bo u khoi queue
		for(int v = 0; v < n; v++) {
			if(G[u][v] == 1) { //Co canh (u, v) thuoc E
				if(dist[v] == oo) {
					Q.push(v);
					preve[v] = u; //dinh truoc dinh v la u
					dist[v] = dist[u] + 1;
				}
			}
		}
	}
}
void findPath(int u, int v) { //Tim duong di tu u -> v
	bfs(u);
	while(v != u) {
		cout << v << " <- ";
		v = preve[v]; 
	} cout << u << endl;
}
int main() 
{
	findPath(0, 2);
	/*cout << "graph cay {" << endl;
	for(int u = 0; u < n; u++) {
		cout << u << " -- " << preve[u] << endl;
	} cout << "}" << endl;
	for(int u = 0; u < n; u++) {
		cout << u << " - " << dist[u] << endl;
	}
	int u = 2, s = 0;
	while(u != s) {
		cout << u << " <- ";
		u = preve[u];
	} 
	cout << s; */
	return 0;
}
