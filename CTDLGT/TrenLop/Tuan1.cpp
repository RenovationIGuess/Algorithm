#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
const int VC = -1000;

//neu so to hon thi dung long long a 
//su dung test: a[] = {2, -10, 11, -4, 13, -5, 2}

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

//giai thuat 1 - O(n^3)
void GT1(int a[], int n)
{
    int max = VC;
    int st = 0, en = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            int s = 0;
            for(int k = i; k <= j; ++k)
            {
                s += a[k];
            }
            if(s > max) 
            {
                max = s;
                st = i;
                en = j;
            }
        }
    }

    cout << "MAX = " << max << endl;
    cout << "Day con: ";
    for(int i = st; i <= en; ++i)
    {
        cout << a[i] << " ";
    } cout << endl;
}

//giai thuat 2 - O(n^2)
void GT2(int a[], int n)
{
    int max = VC;
    int st = 0, en = 0;
    for(int i = 0; i < n; ++i)
    {
        int s = 0;
        for(int j = i; j < n; ++j)
        {
            s += a[j];
            if(s > max) 
            {
                max = s;
                st = i;
                en = j;
            }
        }
    }

    cout << "MAX = " << max << endl;
    cout << "Day con: ";
    for(int i = st; i <= en; ++i)
    {
        cout << a[i] << " ";
    } cout << endl;
}

//giai thuat 3 - O(n)
void GT3(int a[], int n)
{
    int *s = new int[n];
    s[0] = a[0];
    int max = s[0];
    int p = 0;
    for(int i = 1; i < n; ++i)
    {
        if(s[i - 1] > 0)
            s[i] = s[i - 1] + a[i];
        else s[i] = a[i];
        if(max < s[i]) 
        {
            max = s[i];
            p = i;
        }
    }

    cout << "MAX = " << max << endl;
    cout << "Day con: ";
    for(int i = 0; i <= p; ++i)
    {
        cout << a[i] << " ";
    } cout << endl;
    delete[]s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand((int)time(0));

    int n;
    cin >> n;
    int *a = new int[n];

    //sinh rand
    /*for(int i = 0; i < n; ++i)
    {
        a[i] = random(-100, 100);
    }*/

    //nhap tu ban phim
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    GT1(a, n);
    //GT2(a, n);
    //GT3(a, n);

    delete[]a;
    return 0;
}
