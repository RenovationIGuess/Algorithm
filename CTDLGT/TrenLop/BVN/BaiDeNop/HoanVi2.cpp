#include<iostream>
#include<string>
#define MAX 1001
using namespace std;

string s;
int a[MAX];
//luu xau goc
int b[MAX];
//luu hoan vi
int check[MAX] = {0};
int n;

//converted
void Cvt()
{
    for(int i = 0; i < s.size(); ++i)
    {
        a[i + 1] = s[i] - '0';
        //check[a[i + 1]] = 1;
    }
    //cout << a[n] << endl;
}

void print()
{
    for(int i = 1; i <= n; ++i)
    {
        cout << b[i];
    } cout << endl;
}

void Try(int k)
{
    for(int i = 1; i <= n; ++i)
    {
        if(!check[a[i]])
        {
            b[k] = a[i];
            check[a[i]] = 1;
            if(k == n)
            {
                print();
            }
            else Try(k + 1);
            check[a[i]] = 0;
        }
    }
}

int main()
{
	cout << "Nhap so: ";
    cin >> s;
    n = s.size();
    Cvt();
	cout << "Cac hoan vi la:\n";
    Try(1);
    return 0;
}
