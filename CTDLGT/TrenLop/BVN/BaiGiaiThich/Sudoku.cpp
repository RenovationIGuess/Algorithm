#include<iostream>
#define N 9
//kich co cua bang sudoku hien tai: 
using namespace std;

int n;
int grid[N][N];

//Used In Column - kiem tra so dinh dien da co trong cot do chua?
bool UIC(int col, int num)
{
	for(int row = 0; row < N; ++row)
	{
		if(grid[row][col] == num)
			return true;
	}
	return false;
}

//Used In Row - kiem tra so dinh dien da co trong hang chua?
bool UIR(int row, int num)
{
	for(int col = 0; col < N; ++col)
	{
		if(grid[row][col] == num)
			return true;
	}
	return false;
}


//Used In Box
bool UIB(int boxStartRow, int boxStartCol, int num)
{
	for(int row = 0; row < 3; ++row)
	{
		for(int col = 0; col < 3; ++col)
		{
			if(grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
		}
	}
	return false;
}

void printGrid()
{
	for(int row = 0; row < N; ++row)
	{
		for(int col = 0; col < N; ++col)
		{
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}

//Is Safe? Kiem tra xem co dien duoc so vao ko
bool IS(int row, int col, int num)
{
	return !UIR(row, num) && !UIB(row - row % 3, col - col % 3, num) && !UIC(col, num) && grid[row][col] == 0;
}

//Find Unassigned Location - tim vi tri chua duoc danh so
//neu tat ca vi tri da duoc danh so => checked
bool FUL(int &row, int &col)
{
	for(row = 0; row < N; ++row)
	{
		for(col = 0; col < N; ++col)
		{
			if(grid[row][col] == 0)
				return true;
		}
	}
	return false;
}

bool Solve()
{
	int row, col;
	
	//neu ko con vi tri trong nao
	if(!FUL(row, col))
		return true;
		
	for(int num = 1; num <= 9; ++num)
	{
		if(IS(row, col, num))
		{
			grid[row][col] = num;
			if(Solve())
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	/*
	3 0 6 5 0 8 4 0 0
	5 2 0 0 0 0 0 0 0
	0 8 7 0 0 0 0 3 1
	0 0 3 0 1 0 0 8 0
	9 0 0 8 6 3 0 0 5
	0 5 0 0 9 0 6 0 0
	1 3 0 0 0 0 2 5 0
	0 0 0 0 0 0 0 7 4
	0 0 5 2 0 6 3 0 0
	*/
	cout << "Enter the Sudoku: " << endl;
	for(int row = 0; row < N; ++row)
	{
		for(int col = 0; col < N; ++col)
		{
			cin >> grid[row][col];
		}
	}
	
	if(Solve() == true)
	{
		cout << "\nThe result is: " << endl;
		printGrid();
	}
	else cout << "No solution exists";
	return 0;
}
