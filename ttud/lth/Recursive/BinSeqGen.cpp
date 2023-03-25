#include <bits/stdc++.h>
#define N 25

using namespace std;

int res[N]; // store the result - Ex: 000, 111...
int n;

void input() {
    scanf("%d", &n);
}

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << res[i];
    } cout << endl;
}

void Try(int k) {
    for (int i = 0; i < 2; ++i) {
        res[k] = i;
        if (k == n) print();
        else Try(k + 1);
    }
}

int main() {
    input();
    Try(1);
    return 0;
}
