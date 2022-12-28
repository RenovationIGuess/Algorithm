#include<stdio.h>
int main() {
	int n, p, s, min; 
	scanf("%d", &n);
	int t[n][2], cnt[n + 1]; //t stand for tree
	
	for (int k = 0; k <= n; k++) cnt[k] = 0; 			
	
	for (int i = 0; i < n; i++) {						 
		for (int j = 0; j < 2; j++) {					
			scanf("%d", &t[i][j]);
			cnt[t[i][j]]++;
		}
	}
	cnt[0] = n + 1; //Cho cnt[0] = 1 gtri khong xet trong dk de khong xet nhan 0
	for (int k = 0; k < n - 1; k++) {
		min = n + 1;
		for (int i = 0; i < n; i++) {
			if (cnt[t[i][0]] == 0 || cnt[t[i][1]] == 0) continue; //Khong xet nhung dinh da = 0 nx
			if (cnt[t[i][0]] == 1) {
				if (min > t[i][0]) {
					min = t[i][0];
					p = i;
				}
			}
			if (cnt[t[i][1]] == 1) {
				if (min > t[i][1]) {
					min = t[i][1];
					p = i;
				}
			}
		}
		cnt[t[p][0]]--;
		cnt[t[p][1]]--;
		if (cnt[t[p][0]] == 0) printf("%d ", t[p][1]);
		else printf("%d ", t[p][0]);
	}
	return 0;
}
