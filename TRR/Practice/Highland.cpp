#include<iostream>
using namespace std;
const int MAX = 1000; //1e3
int n; //Quang duong
int k; //Khoang chieu
int m; //So den
int visited[MAX + 1]; //Kiem tra vi tri nao da dc thap sang
int visited1[MAX];

int res(int u) {
	if(u >= 0 && u <= k) return 0;
	else return u - k;
}

int res1(int u) {
	if(u + k > n) return n;
	else return u + k;
}

int check() {
	for(int i = 1; i <= n; i++) {
		if(visited1[i] == 0) return 1;
	}
	return 0;
}

int cnt() { //dem so khoang ko dc chieu sang
	int space = 0, dec = 1; //space la so khoang chua sang, dec de xem co out hay khong
	for(int i = 1; i <= n; i++) {
		if(visited1[i] == 0) {
			dec = 0;
			visited1[i] = 1;
			++space;
		} else {
			if(dec == 1) continue;
			else break;
		}
	}
	return space;
}

int main() {
	int l = 0; //so bong den can them
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		/*for(int j = res(x); j <= res1(x); j++) {
			if(visited[j] == 0) visited[j] = 1; //sang den den j
		} */
		for(int k = res(x) + 1; k <= res1(x); k++) {
			if(visited1[k] == 0) visited1[k] = 1;
		}
	}
	/*for(int i = 0; i <= n; i++) {
		cout << visited[i] << " ";
	} cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << visited1[i] << " ";
 	}*/
	if(check() == 0) {
		l = 0;
	} else {
		while(check() != 0) {
			int s = cnt();
			if((s % (2*k)) == 0) {
				l += s/(2*k);
			} else l += (int)(s/(2*k)) + 1; 
			
		}
	}
	cout << l; 
	return 0;
}

/*int countPlace(vector<int> a, int k)
{
    int d =0;
    a.push_back(INT_MAX);
    while(a.size()>1){
        int t = 0;
        int x = a[t] + k ;
        t++;
        while(a[t] <= x && t < a.size() -1) t++;
        t--;
        if(t!=0){
            x += k;
            while(a[t]<=x) t++;
            a.erase(a.begin(),a.begin()+t);
            d++;
        }else{
            d++;
            a.erase(a.begin());
        }    
    }
    return d;
}*/
