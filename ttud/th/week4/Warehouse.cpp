#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, T, D;
int a[MAX];
int t[MAX];
int f[MAX][101];
int res;

void input()
{
    scanf("%d%d%d", &N, &T, &D);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &t[i]);
    }
}

void solve()
{
    res = -10000000;
    /* for (int i = 1; i <= D; ++i)
    {
        for (int k = 1; k <= T; ++k)
        {
            if (k < t[i])
                f[i][k] = 0;
            else
                f[i][k] = a[i];
        }
    } */
    for (int k = 1; k <= T; ++k) {
        if (k < t[1]) f[1][k] = 0;
        else f[1][k] = a[1];
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int k = 1; k <= T; ++k)
        {
            if (k < t[i])
                f[i][k] = 0;
            else
            {
                int cur_max = -10000000;
                for (int j = i - D; j <= i - 1; ++j)
                {

                    if (cur_max < (f[j][k - t[i]] + a[i]))
                    {
                        cur_max = f[j][k - t[i]] + a[i];
                    }
                }
                f[i][k] = cur_max;
                // cout << "i: " << i << " | k: " << k << " | f[i][k]: " << f[i][k] << endl;
                if (res < f[i][k])
                    res = f[i][k];
            }
        }
    }

    // for (int i = 1; i <= N; ++i)
    // {
    //     for (int k = 1; k <= T; ++k)
    //     {
    //         cout << f[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << res << endl;
}

int main()
{
    input();
    solve();
    return 0;
}

// 6 6 2
// 6 8 5 10 11 6
// 1 2 2 3 3 2