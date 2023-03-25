#include<bits/stdc++.h>
#define N 100000
using namespace std;

int n, k;
int a[N];
double res;
vector<int> cur_child;
set<double> list_of_res;

void input() {
    res = -999999.0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

// Function to find the maximum element
double findMax(set<double> my_set)
{
    // Get the maximum element
    int max_element;
    if (!my_set.empty())
        max_element = *my_set.rbegin();
 
    // return the maximum element
    return max_element;
}

void solve() {
    for (int i = 0; i <= n - k; ++i) {
        int cur_sum = 0;
        double cur_ave;
        int j;
        for (j = i; j <= i + k - 1; ++j) {
            cur_sum += a[j];
        }
        cur_ave = (double)cur_sum / k;
        // printf("Sum: %d - Divide: %d - Result: %lf\n", cur_sum, k, cur_ave);
        if (res < cur_ave) res = cur_ave;
        // list_of_res.insert(cur_ave);
        if (i < n - k) {
            for (j = i + k; j < n; ++j) {
                cur_sum += a[j];
                cur_ave = (double)cur_sum / (j - i + 1);
                // printf("Sum: %d - Divide: %d - Result: %lf\n", cur_sum, j - i + 1, cur_ave);
                // list_of_res.insert(cur_ave);
                if (res < cur_ave) res = cur_ave;
            }
        }
    }
    printf("%.5lf\n", res);
}

int main() {
    input();
    solve();
    // int b = 11;
    // int c = 3;
    // double d = (double)b / c;
    // printf("%.5lf\n", d);
    return 0;
}