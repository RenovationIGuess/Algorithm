// CPP program to find maximum sum subsequence
// such that elements are at least k distance
// away.
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int N, int k)
{
	// MS[i] is going to store maximum sum
	// subsequence in subarray from arr[i]
	// to arr[n-1]
	int MS[N];

	// We fill MS from right to left.
	MS[N - 1] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (i + k + 1 >= N)
			MS[i] = max(arr[i], MS[i + 1]);
		else
			MS[i] = max(arr[i] + MS[i + k + 1], MS[i + 1]);
	}

	return MS[0];
}

// Driver code
int main()
{
	int N = 10, k = 2;
	int arr[] = { 50, 70, 40, 50, 90, 70, 60, 40, 70, 50 };
	cout << maxSum(arr, N, k);
	return 0;
}
