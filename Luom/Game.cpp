#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int snt(int n)
{
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int findmem(int n)
{
    int num = 0;
    if(snt(n)) return 0;
    for(int i = n - 1; i >= 2; --i)
    {
        if(n % i == 0) num++;
    }
    return num;
}

int solve(int n)
{
    int min = 99999;
    int res;
    for(int i = 2; i <= n - 1; ++i)
    {
        if(n % i == 0)
        {
            if(snt(n - i)) return i;
            int num = findmem(n - i);
            if(num < min)
            {
                min = num;
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // even - Halley's sister, odd - Halley
        int turn = -1;
        while(!snt(n) && n > 1)
        {
            n -= solve(n);
            turn++;
        } 
        if(turn % 2 == 0) cout << "His daughter" << endl;
        else cout << "Halley" << endl; 
    }
    return 0;
}