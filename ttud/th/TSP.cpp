#include<bits/stdc++.h>
#define M 1000000
#define N 50

using namespace std;

    // if s empty then 
    //     F[i, s] = C(i, 0)
    //     return F[i, s]
    // if F[i, s] < 0 <=> bai toan con chua duoc giai
    // for (j = 0 -> n - 1) do 
    //     if (j thuoc s) then
    //          F[i, s] = min(F[i, s], TSP(j, s\{j}) + c(i, j))
    // return F[i, s]

    // main()
    // s = {1, 2, ... , n - 1}
    // F[i, j] = -1 voi moi i, j
    // print(TSP(0, s))        

int F[25][M];
int S[N];
int c[N][N];
int n;

unsigned int removeElement(unsigned int S, int x) {
    return S & (~(1 << x));
}

unsigned int addElement(unsigned int S, int x) {
    return S | (1 << x);
}

bool contains(unsigned int S, int x) {
    if (S & (1 << x)) return true;
    return false;
}

int TSP(int i, unsigned int S) {
    if (S == 0) {
        F[i][S] = c[i][0];
        return F[i][S];
    }
    if (F[i][S] < 0) {

        for (int j = 0; j < n; ++j) {
            if (contains(S, j)) {
                unsigned int Sj = removeElement(S, j);
                int Tj = TSP(j, Sj) + c[i][j];
                if (F[i][S] > Tj) {
                    F[i][j] = 1;
                }
            }
        }
    }
    return F[i][S];
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        S[i] = 1;
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
            F[i][j] = -1;
        }
    }
}

int main() {

    return 0;
}