#include <bits/stdc++.h>
#define N (int)1e6
#define MOD (int)1e9 + 7
using namespace std;

int n;
int a[N];
int SC[N]; // Tong chan
bool BC[N]; // kiem tra xem truoc do co tong chan ton tai k?
int SL[N]; // Tong le
bool BL[N]; // kiem tra xem truoc do co tong le ton tai k?
int res;

void input() {
    // input
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    // init
    res = -999999;
}

void solve() {
    int length = 0;

    // Dieu kien dau
    if (a[1] % 2 == 0) {
        SC[1] = a[1];
        BC[1] = true;
        length++;
        BL[1] = false;
    } else {
        SL[1] = a[1];
        BC[1] = false;
        BL[1] = true;
    }

    // QHD
    for (int i = 2; i <= n; ++i) {
        // Neu a[i] chan
        if (abs(a[i]) % 2 == 0) {
            // Neu truoc do la tong chan va tong chan > 0
            if (BC[i - 1] && SC[i - 1] > 0) {
                SC[i] = SC[i - 1] + a[i];
            } else {
                // Neu khong thi bat dau lai tong chan
                SC[i] = a[i];
            }
            BC[i] = true;
            length += 2;

            // Tinh tong le
            if (BL[i - 1]) {
                // le = le + chan => danh dau tong dang la le
                SL[i] = SL[i - 1] + a[i];
                BL[i] = true;
            } else {
                // Khong ton tai tong le
                BL[i] = false;
            }
        } else {
            // Neu a[i] le
            if (BL[i - 1] && SL[i - 1] > 0) {
                // Cap nhat tong chan - le + le = chan
                SC[i] = SL[i - 1] + a[i];
                BC[i] = true;
                length++;
            } else {
                BC[i] = false;
            }
            
            // Neu truoc do la tong chan va tong chan > 0
            if (BC[i - 1] && SC[i - 1] > 0) {
                // Cap nhat tong le
                SL[i] = SC[i - 1] + a[i];
            } else {
                SL[i] = a[i];
            }
            BL[i] = true;
        }
    }

    if (length > res) res = length;
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}