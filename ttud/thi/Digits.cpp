#include<bits/stdc++.h>
#define T 55
using namespace std;

int t;
int N; // gia tri cua test
int res; // ket qua cua test hien tai
char c[] = {'H', 'U', 'S', 'T', 'O', 'I', 'C', '\0'};
int charsLength = 6; // so ky tu - 1
map<char, int> a;
int used[11]; // 0 - unused / 1 - used

bool check() {
    int soictValue = a[c[2]]*10000 + a[c[4]]*1000 + a[c[5]]*100 + a[c[6]]*10 + a[c[3]];
    int hustValue = a[c[0]]*1000 + a[c[1]]*100 + a[c[2]]*10 + a[c[3]];
    int totalValue = soictValue + hustValue;
    if (totalValue == N) return true;
    return false;
}

void Try(int k) {
    for (int i = 0; i <= 9; ++i) {
        if (used[i] == 0) {
            if (i == 0) {
                if (k == 0 || k == 2) continue;
            }
            a[c[k]] = i;
            used[i] = 1;
            if (k < charsLength) {
                Try(k + 1);
            } else {
                if (check()) {
                    res++;
                }
            }
            used[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        res = 0;
        cin >> N;
        int size = trunc(log10(N)) + 1;
        if (size > 6) {
            cout << 0 << endl;
            continue;
        }
        memset(used, 0, 11);
        Try(0);
        cout << res << endl;
    }
    return 0;
}
