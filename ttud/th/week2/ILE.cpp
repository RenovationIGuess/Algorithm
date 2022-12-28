#include<bits/stdc++.h>

using namespace std;

int n, M; // input
int f, res; // sum, result
int run_time = 0;

void print(int *a) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    } cout << endl;
}

void Try(int k, int *x, int *a, int *t) {
    int endValue = (M - f - (t[n - 1] - t[k])) / a[k]; 
    for (int v = 1; v <= endValue; ++v) {
        x[k] = v;
        f += a[k] * x[k];
        // cout << k << endl;
        if (k < n - 1) {
            Try(k + 1, x, a, t);
            f -= a[k] * x[k];  
        } else {
            if (f == M) {
                res++;
                // print(x);
            }
            f -= a[k] * x[k];
            run_time++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> M;
    int *a = new int[n];
    int *t = new int[n];
    int *x = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            t[i] = a[i];
        } else {
            t[i] = t[i - 1] + a[i];
        }
    }
    f = 0;
    res = 0;
    Try(0, x, a, t);
    // cout << run_time << endl;
    cout << res << endl;
    return 0;
}