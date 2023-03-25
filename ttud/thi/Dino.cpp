#include<bits/stdc++.h>
#define N 100000
using namespace std;

int n;
int p[N];
string s;
stack<int> cage;
queue<int> tunnel;

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        cage.push(p[i]);
    } 
    cin >> s;
}

void solve() {
    for (int i = 0; i < s.length(); ++i) {
        if (s.at(i) == 'C') {
            int id = cage.top(); cage.pop();
            tunnel.push(id);
        } else {
            int id = tunnel.front(); tunnel.pop();
            cage.push(id);
        }
    }

    while (!cage.empty()) {
        cout << cage.top() << " ";
        cage.pop();
    }
}

int main() {
    input();
    solve();
    return 0;
}