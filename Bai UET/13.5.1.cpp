#include<stdio.h>
#include<cstdlib>
int main() {
	int x1, v1, x2, v2; scanf("%d %d %d %d", &x1, &v1, &x2, &v2);
	//Bai toan 2 vat(...) chuyen dong cung chieu gap nhau hoac khong
	int a = x2 - x1, b = v1 - v2; //Tgian de 2 vat gap nhau: t = a/b (khoang cach : kcach van toc)
	if(a*b < 0) {
		printf("No");
		exit(0);
	}
	int t = a/b;
	if((x1 + t*v1) == (x2 + t*v2)) { //s: quang duong = x + a*v
		printf("Yes");
	} else printf("No");
	return 0;
}
/* C1: #include<stdio.h>
#include<stdlib.h>
int main(){
    int x1,v1,x2,v2,temp1,temp2;
    scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
    if((x2-x1)(v1-v2)<0){
        printf("No");
        exit(0);
    }
    int a=(x2-x1)/(v1-v2);
    if((x1+av1)==(x2+av2)){
        printf("Yes");
    }
    if((x1+av1)!=(x2+a*v2)){
        printf("No");
    }
    return 0;
} */
/* C2: #include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int x1, v1, x2, v2, distance, speed;
    cin >> x1 >> v1 >> x2 >> v2;
    if(x1 < x2 && v1 < v2  x1 > x2 && v1 > v2)
    {
        cout << "NO";
        exit(0);
    }
    distance = x1 - x2;
    speed = v2 - v1;
    if(distance % speed == 0)
    cout << "YES";
    else cout << "NO";
    return 0;
}
*/
