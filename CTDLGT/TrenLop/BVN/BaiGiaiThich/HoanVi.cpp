#include<iostream>
#define MAX 100
#include<algorithm>
using namespace std;

int n;
int check[MAX] = {0};
int a[MAX];
//bool check; 


//khoi tao
/*void create()
{
    for(int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
} */


//output
void print()
{
    for(int i = 1; i <= n; ++i)
    {
        cout << a[i];
    } cout << endl;
} 

//sinh hoan vi
/*void permute()
{ */
    /*
    VD: 13245 -> sinh hoan vi tiep theo?
    -> duyet tu cuoi, tim phan tu lam mat tinh tang
    -> a[i] = 4 < 5
    ke tu j = i + 1 -> n
    -> tim so a[j] min > a[i]
    -> doi cho a[i] a[j]
    -> ke tu i + 1 -> n thi doi cho
    */
    //duyet tu cuoi
    /*int i = n - 1;
    //<=> i = 4
    while(i > 0 && a[i] > a[i + 1]) i--;
    //-> i = 4
    if(i == 0)
    {
        check = true;
        //dat cau hinh cuoi cung
    }
    else
    {
        int k = n;
        //k = 5
        while(a[k] < a[i])
        {
            k--;
        }
        //k = 5
        swap(a[i], a[k]);
        //13254
        int l = i + 1, r = n;
        //l = 5, r = 5
        while(l < r)
        {
            swap(a[l], a[r]);
            l++; r--;
        }
        //-> cau hinh tiep theo la 13254
    }
} */

void Try(int k)
{
    for(int i = 1; i <= n; ++i)
    {
        //Kiem tra duoc xuat hien
        if(!check[i])
        {
            a[k] = i;
            //da dung gia tri i tai vi tri k
            check[i] = 1;
            if(k == n)
            {
                print();
            }
            else
            {
                Try(k + 1);   
            }
            //bo danh dau de tim hoan vi khac  
			check[i] = 0;
        }
    }
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0); */
    //Bai toan hoan vi n so tu nhien
    cout << "Nhap n: ";
    cin >> n;
    //check = false;
    //create();
    /*while(!check)
    {
        print();
        permute();
        
    }*/
    Try(1);
    return 0;
}

/* 
Bai toan hoan vi so tu nhien n
*/
