#include<bits/stdc++.h>
#define N 10000

using namespace std;

int n;
map<char, int> a;
char c[] = { 'I', 'C', 'T', 'H', 'U', 'S', 'K', '\0'};
int charsLength = 6;
int Q = 0;
bool assignedValue[11];

bool check() {
    int ictValue = a[c[0]]*100 + a[c[1]]*10 + a[c[2]];
    int k62Value = a[c[6]]*100 + 62;
    int hustValue = a[c[3]]*1000 + a[c[4]]*100 + a[c[5]]*10 + a[c[2]];
    int totalValue = ictValue - k62Value + hustValue;
    // if (Q < 5) {cout << totalValue << endl;}
    if (totalValue == n) return true;
    return false;
}

void Try(int k) {
    for (int i = 1; i <= 9; ++i) {
        if (!assignedValue[i]) {
            a[c[k]] = i;
            assignedValue[i] = true;
            if (k < charsLength) {
                Try(k + 1);
            } else {
                if (check()) {
                    Q++;
                }
            }
            assignedValue[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= 9; ++i) {
        assignedValue[i] = false;
    }
    Try(0);

    cout << Q << endl;
    return 0;
}