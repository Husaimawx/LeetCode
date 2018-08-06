#include <iostream>
#include <vector>
using namespace::std;

void checkValid(vector<vector<char>>& board, int x, int y, int* num)
{
	for (int i = 0; i<9; i++)
	{
		if (board[x][i] != '.')
			num[board[x][i] - 49] = 0;
		if (board[i][y] != '.')
			num[board[i][y] - 49] = 0;
	}
	int basex = x - x % 3;
	int basey = y - y % 3;
	for (int i = basex; i<basex + 3; i++)
	{
		for (int j = basey; j<basey + 3; j++)
		{
			if (board[i][j] != '.')
				num[board[i][j] - 49] = 0;
		}
	}
	return;
}

bool solveSudokuAux(vector<vector<char>>& board, int x, int y)
{
	if (x == 9)
		return true;

	if (board[x][y] != '.')
	{
		if (y == 8)
		{
			y = 0;
			x++;
		}
		else
			y++;
		return solveSudokuAux(board, x, y);
	}

	int valid[9] = { 1,1,1,1,1,1,1,1,1 };
	checkValid(board, x, y, valid);
	int newx, newy;
	if (y == 8)
	{
		newy = 0;
		newx = x + 1;
	}
	else
	{
		newx = x;
		newy = y + 1;
	}
	for (int i = 0; i<9; i++)
	{
		if (valid[i] == 1)
		{
			board[x][y] = 49 + i;
			if (solveSudokuAux(board, newx, newy))
				return true;
		}
	}
	board[x][y] = '.';
	return false;
}

bool solveSudoku(vector<vector<char>>& board) {
	return solveSudokuAux(board, 0, 0);
}

int main()
{
	/*
	char line1[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line2[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line3[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line4[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line5[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line6[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line7[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line8[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line9[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };*/
	
	char line1[] = { '.', '5', '.', '.', '7', '.', '.', '.', '.', };
	char line2[] = { '.', '.', '.', '.', '4', '9', '1', '.', '.', };
	char line3[] = { '9', '6', '.', '1', '.', '.', '.', '.', '8', };
	char line4[] = { '.', '.', '2', '.', '.', '.', '.', '1', '.', };
	char line5[] = { '.', '.', '.', '.', '.', '.', '.', '.', '.', };
	char line6[] = { '.', '8', '.', '.', '.', '.', '6', '.', '.', };
	char line7[] = { '8', '.', '.', '.', '.', '7', '.', '4', '9', };
	char line8[] = { '.', '.', '4', '6', '5', '.', '.', '.', '.', };
	char line9[] = { '.', '.', '.', '.', '3', '.', '.', '7', '.', };

	vector<char> v1(line1, line1 + 9);
	vector<char> v2(line2, line2 + 9);
	vector<char> v3(line3, line3 + 9);
	vector<char> v4(line4, line4 + 9);
	vector<char> v5(line5, line5 + 9);
	vector<char> v6(line6, line6 + 9);
	vector<char> v7(line7, line7 + 9);
	vector<char> v8(line8, line8 + 9);
	vector<char> v9(line9, line9 + 9);

	vector<vector<char>> input;
	input.push_back(v1);
	input.push_back(v2);
	input.push_back(v3);
	input.push_back(v4);
	input.push_back(v5);
	input.push_back(v6);
	input.push_back(v7);
	input.push_back(v8);
	input.push_back(v9);

	if (solveSudoku(input))
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << input[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "No Valid Solution";
	}
	return 0;
}

