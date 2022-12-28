#include<iostream>
#include<algorithm>
using namespace std;

bool check = false;

void change(int a[], int n) {
	int i = n - 2;
	while(i > 0 && a[i] > a[i + 1]) i -= 1;
	if(i == 0 && ) check = true;
	else {
		
		int k = n - 1;
		while(a[k] < a[i]) k--;
		swap(a[k], a[i]);
		reverse(a[i + 1], a[k]);
	}
}

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; ++i) a[i] = i + 1; 
	do {
		for(int i = 0; i < n; ++i) {
			cout << a[i];
		} cout << " ";
		change(a, n);
	} while(check == false);
	delete[]a;
	return 0;
}
