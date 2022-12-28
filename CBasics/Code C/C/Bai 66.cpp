#include<stdio.h>
#include<string.h>
int main() {
	char c;
	char s[100];
	scanf("%c", &c);
	scanf("%s", s);
	int a = 0;
	for (int i = 0; i < strlen(s); i++) { /* Mot chut chu thich ve so phan tu va vong lap
- s[?] voi ? la so phan tu VD: ? = 100 thi se co 99 phan tu chay tu 1 => 99
- Khi tao vong lap for voi i chay tu 0 va i < strlen (do dai cua xau) <=> trong VD tren la i < 99 tuc la i chay tu 0 => 98 van la 99 phan tu */
		if (s[i] == c) { //Ky tu ta phai them dau '' (ke ca la so VD: '3')
			a++;
		}	
	}
	printf("%d", a);
	return 0;
}
