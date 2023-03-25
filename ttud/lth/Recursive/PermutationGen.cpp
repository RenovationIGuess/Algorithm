#include <bits/stdc++.h>
#define N 51
using namespace std;

int seq[N];
int n;
bool used[N];

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << seq[i] << " ";
    } cout << endl;
}

void Try(int k) {
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            seq[k] = i;
            used[i] = true;
            if (k == n) print();
            else Try(k + 1);
            used[i] = false;
        }
    }
}

int main() {
    fill_n(used, N, false);
    scanf("%d", &n);
    Try(1);
    return 0;
}