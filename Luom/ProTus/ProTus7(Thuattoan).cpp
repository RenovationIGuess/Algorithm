#include<stdio.h>
#include<stdbool.h>
#include<cstdlib>
bool check(double a[], double b[], int n);
void RA(double a[], int n);
int main() {
	int n; scanf("%d", &n);
	double a[n], b[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &a[i], &b[i]);
	}
	RA(a, n); 
	RA(b, n);
	if (check(a, b, n)) {
		printf("Yes");
	} else printf("No");
	return 0;
}
bool check(double a[], double b[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] <= b[i]) {
			return false;
			break;
		}
		return true;
	}
	
}
void RA(double a[], int n) { //RA: rearrage
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
