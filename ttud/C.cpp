#include <bits/stdc++.h>

using namespace std;
/*
12342532423
3
*/
int indexToWrite = 1;
int k;
char *str = (char*)malloc(sizeof(char)*100001);
char ans[1000];
void del(){
	if (indexToWrite > 0) indexToWrite--;
	cout << "Deleted " << ans[indexToWrite] <<endl;
	ans[indexToWrite] = '\0';
}

void write(char a){
	cout << "Wrote " << a << endl;
	ans[indexToWrite] = a;
	if (indexToWrite < k) indexToWrite++;
    ans[indexToWrite] = '\0';
}

int main(){

    cin >> str;
    cin >> k;
    
    
	ans[0] = str[0];
	
    for (int i = 1; i < strlen(str); i++){
    	if (indexToWrite == 0) write(str[i]);
        else {
        	if (str[i] > ans[indexToWrite-1]) {
        		while(str[i] > ans[indexToWrite-1] && indexToWrite >= 1)
        			del();
        		write(str[i]);
			}
			else if (str[i] < ans[indexToWrite-1]){
				write(str[i]);
			}
		}
    }
    for (int i = 0; i < k; i++){
        cout << ans[i];
    }
}
