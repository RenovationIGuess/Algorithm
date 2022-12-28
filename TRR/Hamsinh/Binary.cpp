#include<iostream>
using namespace std;

bool check = false;

void BinaryGeneration(int a[], int n) {//, int k, bool *check) {
	int i = n - 1;
	while(i > 0 && a[i] == 1) {i -= 1;}
		if(i == 0 && a[i] == 1) {
			check = true;
		} else {
			a[i] = 1;
			for(int j = i + 1; j < n; j++) {
				a[j] = 0;
			}
		}
}
int main() {
	int n; 
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; ++i) {
		a[i] = 0;
	}
	do {
		for(int i = 0; i < n; ++i) {
			cout << a[i];
		}
		cout << " ";
		BinaryGeneration(a, n);
	} while(check == false); 
	/*bool check = false;
	while(!check)
	{
		BinaryGeneration(a, n, n/2, &check);
		for(int i = n/2; i < n; ++i) {
			cout << a[i];
		}
		cout << " ";
		
	} */
	delete[]a;
	return 0;
}
