#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int n;
int F[MAX][2];
int a[MAX];
deque<int> d;
int res;

void input() {
    scanf("%d%d", &n);
    for (int i = 1; i <= n; ++i) {
        int value;
        scanf("%d", &a[i]);
        // a.push_back(value);
        // F[i] = a[i];
    }
}

// Function to find the maximum sum
// int solve()
// {
//     if (n == 1) {
//         return a[0];
//     }
    
//     F[0][0] = 0;
//     F[0][1] = a[0];
    
//     for (int i = 1; i < n; i++) {
//         F[i][1] = F[i - 1][0] + a[i];
//         F[i][0] = max(F[i - 1][1], 
//                        F[i - 1][0]);
//     }
    
//     // Return the maximum sum
//     return max(F[n - 1][0], F[n - 1][1]);
// }

int solve(int arr[], int n) {
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }

    return dp[n-1];
}

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << F[i] << " ";
    } cout << endl;
}

// void solve() {
//     // deque<int>::iterator iter;

//     for (int i = L1 + 1; i <= n; ++i) {
//         if (!d.empty()) {
//             while(F[d.front()] <= F[i - L1]) {
//                 d.pop_front();
//                 if (d.empty()) break;
//             }
//         }
//         d.push_back(i - L1);
//         F[i] = F[d.front()] + a[i];
//         cout << F[i] << endl;
//     }

//     // print();

//     res = *max_element(F + 1, F + n + 1);
//     cout << res << endl;
// }

int main() {
    input();
    cout << solve(a, n) << endl;
    return 0;
}