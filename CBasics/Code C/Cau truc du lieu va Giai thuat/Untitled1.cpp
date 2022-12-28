#include<stdio.h>
int lam(int a[], int n) {
    int b = 0; //b la tong cua cac phan tu trong day
    for (int i = 0; i < n; i++) {
        b += a[i];
    
    }
	return b;
}
int main() {
    int n;
    int a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", lam(a, n));
    return 0;
}

