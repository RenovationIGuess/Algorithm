#include<iostream>
using namespace std;

int n, k;
int a[100]; 
bool check;

void ok() {
	int i = k;
	while(a[i] == 1 && i > 0) i--;
	if(i == 0) {
		check = true;
	}
	else {
		a[i]--; // 1 1 1
		int d = k - i + 1; //3
		k = i; //1
		for(int j = i + 1; j <= i + d/a[i]; ++j) a[j] = a[i];
		//2 -> 4: 1 1 1 1 
		k += d/a[i]; //4
		if(d % a[i] != 0) {
			k++;
			a[k] = d % a[i];
		}
	}
}

int main() {
	cin >> n;
	check = false;
	k = 1;
	a[k] = n;
	while(check == false) {	
		cout << "(";
		for(int l = 1; l <= k - 1; ++l) {
			cout << a[l] << " ";
		} cout << a[k] << ") ";
		ok();
	}
	return 0;
}
