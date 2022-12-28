#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[1000];
	for (int i = 0;  i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
		
	} 
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
/* a[i] a[i+1], tao bien c, gan c = a[i], a[i] = a[i+1] khi do day so se nhu sau
=> c a[i] sau do chi can cho c = a[i+1] */
