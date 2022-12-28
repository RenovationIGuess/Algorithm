#include<stdio.h>
#define MAX 100

int pi[MAX];
int rank[MAX];

void makeset(int x) {
	pi[x] = x;
	rank[x] = 0;
}

int find(int x) {
	while(x != pi[x]) x = pi[x];
	return x;
}

void union1(int x, int y) {
	int rx = find(x);
	int ry = find(y);
	if(rx == ry) return;
	if(rank[rx] > rank[ry]) pi[ry] = rx;
	else {
		pi[rx] = ry;
		if(rank[rx] == rank[ry]) rank[ry] = rank[rx] + 1;
	}
}

void printGraph(int n) {
	printf("graph test\n{\n");
	for(int i = 0; i < n; i++) {
		printf("%d -> %d\n", x, pi[x]);
	}
	printf("}");
}
typedef struct {
	int u, v, w;
} Canh;
Canh dscanh[MAX];
int cmpfunc(const void *a, const void *b) {
	return(*(Canh*)a.w - *(Canh*)b.w);
}
void Kruskal() {
	for(int i = 0; i < m; i++) {
		int min = i;
		for(int j = i + 1; j < m; j++) {
			if(dscanh[j].w < dscanh[min].w) {
				min = j;
			}
		}
		
	}
}
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &dscanh[i].u, &dscanh[i].v, &dscanh[i].w);
	}
	return 0;
}
