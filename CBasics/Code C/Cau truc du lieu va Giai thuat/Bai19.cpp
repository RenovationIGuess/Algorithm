#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n, k; //number of phone numbers
    queue<int> q;
    cin >> n;
    int *Onscreen = new int[n];
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        Onscreen[i] = 0;
    }
    cin >> k;
    for(int i = 0; i < n; i++) {
        if(Onscreen[a[i]] == 0) {
            if(q.size() < k) {
                Onscreen[a[i]] = 1;
                q.push(a[i]);
            } else {
                int u = q.front(); q.pop();
                Onscreen[u] = 0;
                Onscreen[a[i]] = 1;
                q.push(a[i]);
            }
        }
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    delete[]a;
    delete[]Onscreen;
    return 0;
}
