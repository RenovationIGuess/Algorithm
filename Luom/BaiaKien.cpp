#include <iostream>
#include <string>
using namespace std;

int n;
int numberOfPair = 0;

void solveFunc(int a[][2], int skippedIndex[], int index, int x, int y) {
	for(int i = index + 1; i < n; ++i) {
		if(skippedIndex[i] == 0) {
			if (a[i][0] == y && a[i][1] == x) {
				numberOfPair++;
            	skippedIndex[index] = 1;
            	skippedIndex[i] = 1;
            	return;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int a[n][2];
	int skippedIndex[n];

	// input
	cin >> n;
	for (int i = 0; i < n; ++i) {
	skippedIndex[i] = 0;
	for (int j = 0; j < 2; ++j) {
		cin >> a[i][j];
	}
}

// solve
for (int i = 0; i < n - 1; ++i) {
	if (skippedIndex[i] == 0) {
    	int x = a[i][0];
		int y = a[i][1];
		solveFunc(a, skippedIndex, i, x, y);	
	}
}
  
for(int i = 0; i < n; ++i) {
	cout << skippedIndex[i] << " ";
} cout << endl;

		cout << numberOfPair << endl;
	return 0;
}
