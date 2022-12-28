#include<stdio.h>
#include<stdbool.h>
#include<cstdlib>
#include<algorithm>
void RA(double a[], int n);
int main() {
	int n;
	bool check = true;
	scanf("%d", &n);
	double a[n + 1], b[n + 1];
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a[i], &b[i]);
	}
	RA(a, n); 
	RA(b, n);
	for (int i = 0; i < n; i++) {
		if (a[i] <= b[i]) {
			printf("No");
			exit(0);
		}
	}
	printf("Yes");
	return 0;
}

void RA(double a[], int n) { //RA: rearrage
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
