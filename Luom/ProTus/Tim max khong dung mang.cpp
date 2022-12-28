#include<iostream> 
using namespace std;
int main() {
	int n, max, a; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a); 
		if (i == 1) max = a;
		if (a > max) max = a;
	}
	printf("%d", a);
	return 0;
}
