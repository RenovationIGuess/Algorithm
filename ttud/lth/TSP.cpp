#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int N;
int c[MAX_N + 1][MAX_N + 1]; // khoang cach giua 2 diem
int x[MAX_N + 1]; // bieu dien phuong an lo trinh x[1], x[2], ... x[n]
bool appear[MAX_N + 1]; // kiem tra xem da di qua diem i chua
int res; // result
int cmin; // min distance between 2 points
int currentLength;

void TRY (int k) // thu gia tri cho x[k]
{
    for (int v=2; v<=N; v++) {
        if (!appear[v]) {
            x[k] = v;
            currentLength += c[x[k-1]][x[k]];
            appear[v] = true;

            if (k == N) {
                res = min(res, currentLength + c[x[k]][1]);
            }
            else if (currentLength + (N - k + 1)*cmin < res)
                TRY (k+1);

            currentLength -= c[x[k-1]][x[k]];
            appear[v] = false;
        }
    }
}

int main()
{
    //freopen ("a.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cmin = INT_MAX;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            cin >> c[i][j];
            if (i!=j) cmin = min (cmin, c[i][j]);
        }

    res = INT_MAX;
    x[1] = 1; appear[1] = true;
    TRY (2);
    cout << res;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int n;
int c[100][100];
int x[100];
int xopt[100];
int visited[100] = {0};
int fopt = INT_MAX;
int f = 0;
int cmin = INT_MAX;
void Try(int k){
    for(int y = 2;y <= n; y++){
        if(visited[y] == 0){
            x[k] = y;
            visited[y] = 1;
            f += c[x[k-1]][x[k]];
            if(k==n){
                int f1 = f + c[x[n]][x[1]];
                if(f1 < fopt){
                    fopt = f1;
                    for(int i = 1; i<= n; i++){
                        xopt[i] = x[i];
                    }
                }
            }else{
                Try(k+1);
                visited[y] = 0;
                f -= c[x[k-1]][x[k]];
            }
        }

    }
}

int main(){
        freopen ("a.inp", "r", stdin);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            cmin = (cmin > c[i][j] && c[i][j] != 0) ? c[i][j] : cmin;
        }
    }
    x[1] = 1;
    Try(2);
    cout << "The optimal cost = " << fopt << endl;
    cout << "The optimal path: ";
    for(int i = 1; i <= n; i++){
        cout << xopt[i] << " ";
    }
}
*/
