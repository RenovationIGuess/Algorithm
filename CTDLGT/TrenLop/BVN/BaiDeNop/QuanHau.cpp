#include<iostream>
#define MAX 101
using namespace std;

bool Col[15], Row[15], Cx[20], Cn[20];
int n;
int res;
int pos[10][10] = {0};

void redo(int c)
{
	for(int p = 1; p <= 8; ++p)
	{
		if(pos[c][p] != 0)
		{
			pos[c][p] = 0;
		}
	}
}

void Try(int i)
{
    for(int j = 1; j <= 8; ++j)
    {
        if(!Col[i] && !Row[j] && !Cx[i + j - 1] && !Cn[j - i + 8])
        {
            Col[i] = Row[j] = Cx[i + j - 1] = Cn[j - i + 8] = 1;
            redo(i);
            pos[i][j] = 1;
            
            if(i == 8)
            {
                res++; 
                
                cout << "Cach " << res << ":\n";
                
                for(int c = 1; c <= 8; ++c)
                {
                	for(int r = 1; r <= 8; ++r)
                	{
                		if(pos[c][r] != 0)
                		{
                			cout << c << " - " << r << endl;
                			//break;
						}
						//cout << pos[c][r] << " ";
					}
					//cout << endl;
				}
				cout << endl;
            } 
            else Try(i + 1);
            Col[i] = Row[j] = Cx[i + j - 1] = Cn[j - i + 8] = false;
        }
    }
}

int main()
{
    //Mo rong bai toan thanh sx n quan hau trong ban co n * n
    res = 0;
    cout << "Hinh thuc output:\nCach a:\nCot - Hang\n...\nTong so cach xep: ...\n\n"; 
    Try(1);
    cout << "Tong so cach xep la: " << res << endl;
    return 0;
}
