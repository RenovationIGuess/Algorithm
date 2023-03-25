#include<bits/stdc++.h>
#define N 55
using namespace std;

int n;
int b;
int a[N];
int sign[N];
int res;

void input() {
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    res = 0;
}

bool check() {
    int sum = a[0];
    for (int i = 0; i < n - 1; ++i) {
        if (sign[i] == 0) {
            sum -= a[i + 1];
        } else {
            sum += a[i + 1];
        }
    }
    return sum == b;
}

void print() {
    cout << a[0];
    for (int i = 0; i < n - 1; ++i) {
        if (sign[i] == 0) {
            cout << " - " << a[i + 1];
        } else {
            cout << " + " << a[i + 1];
        }
    }
    cout << " = " << b << endl; 
}

void Try(int k) {
    // 0 - (-) / 1 - (+)
    for (int i = 0; i <= 1; ++i) {
        sign[k] = i;
        if (k < n - 2) {
            Try(k + 1);
        } else {
            if (check()) {
                res++;
                print();
            }
        }
    }
}

int main() {
    input();
    Try(0);
    cout << res << endl;
    return 0;
}