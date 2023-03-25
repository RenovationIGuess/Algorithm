#include <bits/stdc++.h>
#define N (int)1e6
using namespace std;

int n;
priority_queue<int> a;
string type;
// int cur_max;

void print() {
    while (!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    } cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // scanf("%d", &n);
    cin >> n;
    // cur_max = -999999;
    // vector<int>::iterator it = a.begin();

    for (int i = 0; i < n; ++i) {
        int value;
        // scanf("%d", &value);
        cin >> value;
        a.push(value);
        // if (value > cur_max) {
        //     cur_max = value;
        //     it++;
        // }
    }

    // print();
    
    do {
        cin >> type;
        if (type == "*") {
            continue;
        }
        if (type == "insert") {
            int value;
            // scanf("%d", &value);
            cin >> value;
            // cout << value << endl;
            a.push(value);
        } else if (type == "delete-max") {
            if (!a.empty()) {
                cout << a.top() << endl;
                a.pop();
            }
        }
    } while (type != "*");

    return 0;
}