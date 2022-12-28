#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int pnum; //peak number
int clock = 1;
int pre[MAX], post[MAX];
void previsit(int v) {
	pre[v] = clock;
	clock++;
}
void postvisit(int v) {
	post[v] = clock;
	clock++;
}
void explore(int v) 
{
	visited[v] = 1; //1: true / 0: false;
	previsit(v);
	for(int u = 0; u < pnum; u++) {
		if(graph[v][u] == 1) {
			if(!visited[u]) explore(u); //!: phu dinh <=> visited u = 0;
		}
	}
	postvisit(v);
}
void dfs ()
{
	for(int v = 0; v < pnum; v++) {
		visited[v] = 0;
	}
	for(int v = 0; v < pnum; v++) {
		if (visited[v] == 0) {
			explore(v);
		}	
	}
}
enum edge {forward, back, cross};
enum edge sort(int u, int v) 
{
	if(pre[u] < pre[v] && post[u] > post[v]) return forward; //Tree || Forward
	if(pre[u] > pre[v] && post[u] < post[v]) return back;
	return cross;
	
}
int main(int argc, char const *argv[]) {
	freopen("dothi.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	int egnum; //egde number
	scanf("%d%d", &pnum, &egnum);
	for(int e = 0; e < egnum; e++) {
		int u, v;
		scanf("%d%d", &u , &v);
		graph[u][v] = graph[v][u] = 1;
	}
	dfs();
	for(int u = 0; u < pnum; u++) {
		printf("\n%d: %d - %d", u, pre[u], post[u]);
	} printf("\n");
	for(int i = 0; i < pnum; i++) {
		for(int j = i + 1; j < pnum; j++) {
			printf("");
		}
	}
	return 0;
}
