#include<iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int myNum, yourNum;
	srand(time(NULL));
	myNum = rand() % (50 - 1 + 1) + 1;//Dang bien = rand() % (max - min + 1) + min => so se thuoc [1;50]
	cout << "Guess my number (between 1 and 50): ";
	cin >> yourNum;
	if (yourNum > myNum) {
		cout << "Your guess was too high." << endl;
	} else if (yourNum < myNum) {
		cout << "Your guess was too small." << endl;
	} else {
		cout <<"You got it!." << endl;
	}
	cout << "The number is " << myNum << ".";
	return 0;
}
