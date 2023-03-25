#include<bits/stdc++.h>
#define MAX 35
using namespace std;

int n, A, B;
int a[MAX];
int cur_sum;
int Q;
int last_index;
 
void generateSubsets(
    int start, 
    int setSize, 
    int S[],
    vector<int>& res)
{
    unsigned int pow_setSize = pow(2, setSize);

    int sum;
 
    for (int counter = 0; counter < pow_setSize; counter++) {
        sum = 0;
 
        for (int j = 0; j < setSize; j++) {
            if (counter & (1 << j))
                sum += S[j + start];
        }
 
        res.push_back(sum);
    }
}
 
int solve(int S[], int N, int A, int B)
{
    vector<int> S1, S2;
 
    generateSubsets(0, N / 2, S, S1);
 
    if (N % 2 != 0)
        generateSubsets(N / 2, N / 2 + 1, S, S2);
    else
        generateSubsets(N / 2, N / 2, S, S2);
 
    sort(S2.begin(), S2.end());
 
    vector<int>::iterator low, high;
 
    int ans = 0;
 
    for (int i = 0; i < S1.size(); i++) {
        low = lower_bound(S2.begin(), S2.end(), A - S1[i]);
        high = upper_bound(S2.begin(), S2.end(), B - S1[i]);
        ans += (high - low);
    }
    return ans;
}

void input() {
    // scanf("%d%d%d", &n, &A, &B);
    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Q = 0;
}

bool check(int sum) {
    return (A <= sum && sum <= B);
}

// void Try(int i) {
//     for (int j = i)
// }

// void solve() {
//     sort(a, a + n);
//     last_index = 0;
//     while (a[last_index] < B) {
//         if (check(a[last_index])) Q++;
//         last_index++;
//     }
//     if (check(a[last_index])) Q++;
//     // cout << a[last_index] << endl;
//     while (a[0] + a[last_index] > B) {
//         last_index--;
//     }
//     if (check(a[0] + a[last_index])) Q++;
//     // cout << last_index << endl;

//     int start_index = 0;
//     int startSum = a[0];
//     while (startSum < B && start_index < last_index) {
//         for (int j = start_index + 1; j < last_index; ++j) {
//             startSum += a[j];
//             if (check(startSum)) {
//                 cout << startSum << endl;
//                 Q++;
//             }
//             startSum -= a[j];
//         }
//         start_index++;
//         startSum += a[start_index];
//     }
    
//     cout << Q << endl;
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    // solve();
    cout << solve(a, n, A, B) << endl;
    return 0;
}