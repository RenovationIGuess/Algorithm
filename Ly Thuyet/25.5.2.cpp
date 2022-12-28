#include<stdio.h>
int Enter_Number_Element(int a[]);
int Find_Max(int a[], int n);
int main() {
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	Enter_Number_Element(a);
	Enter_Number_Element(b);
	if (Find_Max(a, n) > Find_Max(b)) printf("%d", Find_)
	return 0;
}
int Enter_Number_Element(int a[]) {
	for (int i = 0; i < sizeof(a[]); i++) {
		scanf("%d", &a[i]);
	}
}
int Find_Max(int a[], int n) {
	max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > a[0]) max = a[i];
	}
	return max;
}
