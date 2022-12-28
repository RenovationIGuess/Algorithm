#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//Y tuong
//Chen chuoi gom k chu A vao nhung vi tri co the chen

int n, k;
int a[100];
string s = "";
vector<string> res; //result

void make(int i) 
{
	//co n phan tu - k phan tu a => can n - k phan tu
	for(int j = 0; j <= 1; ++j)
	//0 - A, 1 - B 
	{
		a[i] = j;
		if(i == n - k) { //2, 00010, a[2] = 0, a[
			for(int l = 1; l <= n - k; ++l) {
				if(l == 1 && a[l] == 1) {
					//tai vi tri dau la B => chen dc
					string tmp = "";
					tmp += s;
					for(int p = 1; p <= n - k; ++p) 
					{
						if(a[p]) tmp += "B";
						else tmp += "A";	
					}	
					res.push_back(tmp);
				}
				if(l == n - k && a[l] == 1) 
				{
					string tmp = "";
					for(int p = 1; p <= n - k; ++p) {
						if(a[p]) tmp += "B";
						else tmp += "A";
					}
					tmp += s;
					res.push_back(tmp);
				}
				if(a[l] && a[l - 1] && l > 1) {
					string tmp = "";
					for(int p = 1; p <= n - k; ++p) {
						if(p == l) tmp += s;
						if(a[p]) tmp += "B";
						else tmp += "A";
					}
					res.push_back(tmp);
				}
			}
		} else make(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	//tao chuoi gom k phan tu A
	for(int i = 0; i < k; ++i) {
		s += "A";
	}
	//cout << s << endl;
	make(1);
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}	
	return 0;
}

//00010
