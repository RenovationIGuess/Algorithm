#include<iostream>

using namespace std;

long long Mult(long long n)
{
    //cout << n << endl;
    if(n == 0) return 1;
    if(n == 1) return 2;
    long long p = Mult(n/2);
    if(n % 2 == 0) return p * p;
    return 2 * p * p;
}

//VD: n = 5 -> 2 -> 2 -> 2 * 2 -> 2^2 * 2^2 * 2 = 2^5
// n = 3 -> 1 -> 2 * 2 * 2 = 8
// n = 2 -> 2 * 2 = 4

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        --n;
        //cout << n << " " << Mult(n) << endl;
        cout << Mult(n) << endl;
    }
    return 0;
}
