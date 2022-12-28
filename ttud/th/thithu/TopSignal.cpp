#include<bits/stdc++.h>
#define N 1000000

using namespace std;

int a[N + 5];
int Q;
int n;

void input() {
    Q = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

bool check(int k) {
    if (a[k] > a[k - 1] && a[k] > a[k + 1]) {
        return true;
    }
    return false;
}

void Try(int k) {
    if (k < n - 1) {
        if (check(k)) {
            Q++;
            if (k + 2 >= n - 1) {
                Try(k + 1);
            } else Try(k + 2);
        } else {
            Try(k + 1);
        }
    } else {
        if (check(k)) {
            Q++;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    input();
    Try(1);

    cout << Q << endl;
    return 0;
}