#include<bits/stdc++.h>
using namespace std;

string S;
int k;


int main() {

    cin >> S;
    cin >> k;
    int max = S[0] - 97;
    vector<int> vitriMax;
    for (int i = 0 ; i < S.length(); i ++) {
        vitriMax.push_back(i);
    }

    int dem  = 0;
    while(dem < k) {

        for (auto i : vitriMax) {
            if (S[i+dem] - 97 > max) {
                max = S[i+dem] - 97;
                vitriMax.clear();
                vitriMax.push_back(i);
                continue;
            }

            if (S[i+dem] - 97  == max) {
                vitriMax.push_back(i);
            }
        }
        dem ++;
        max = -1;
    
        if (vitriMax.size() == 1) {
            break;
        }
    }
    string res = "";
    for (int i = vitriMax.at(0); i < vitriMax.at(0) + k; i ++) {
        res += S[i];
    }
    
    cout << res;

    return 0;

}