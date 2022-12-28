#include<iostream>

using namespace std;

long long len(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 2;
    long long p = len(n/2);
    if(n % 2 == 0) return p * p;
    return 2 * p * p;
} 

/* VD: n = 3 => goi tiep ham len(1) => return 2;
<=> p = 2/ quay lai ham cu (n % 2) => return 2 * p * p = 8;
*/
//1 -> 3 -> 7 -> 15 ...
// <=> 2^n - 1 => vi tri cua phan tu trung tam (2^n - 1)/2

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        long long l = len(n)/2; //vi tri phan tu chinh giua
        while(1)
        {
            if(n == 1) 
            {
                cout << 1 << endl;
                break;
            }
            if(l == k) 
            {
                cout << n << endl;
                break;
            }
            if(k > l) 
            {
                k = l - (k - l);
                //Neu k o ben phan thi phan doi xung cua no 
                //la VD 1 2 1 3 1 2 1, n = 3, k = 5
                //=> ptu doi xung cua no la: 4 - 1 = 3 <=> do dai 1/2 - (kcach tu k den vi tri giua)
            }
            n--;
            l /= 2;
        }
    }
    return 0;
}