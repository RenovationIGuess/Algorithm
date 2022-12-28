#include<bits/stdc++.h>
#define N 1000000
#define MOD int(1e9 + 7)

using namespace std;

int n;
int a[N];
// int result;

int merge(int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
    int n1 = mid - left;
    int n2 = right - mid + 1;

    int leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; ++i) {
        leftArray[i] = a[left + i];
    }

    for (j = 0; j < n2; ++j) {
        rightArray[j] = a[mid + j];
    }

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            a[k++] = leftArray[i++];
        } else {
            a[k++] = rightArray[j++];
            inv_count = (inv_count + (mid - (i + left))) % MOD;
        }
    }

    while (i < n1) {
        a[k++] = leftArray[i++];
    }

    while (j < n2) {
        a[k++] = rightArray[j++];
    }

    return inv_count;
}

void print() {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    } cout << endl;
}

int solve(int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count = (inv_count + solve(left, mid)) % MOD;
        inv_count = (inv_count + solve(mid + 1, right)) % MOD;
        inv_count = (inv_count + merge(left, mid + 1, right)) % MOD;
    }
    return inv_count;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    // print();
    cout << solve(0, n - 1) << endl;
    return 0;
}