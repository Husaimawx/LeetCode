#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<char,bool> check(vector<vector<char> >& board, int row, int column) {
    map<char,bool> M;
    for(int i = 1;i<=9;i++) {
        M['0'+i] = 0;
    }
    for(int i = 0;i<8;i++) {
        if(i != row && board[i][column] != '.') {
            M[board[i][column]] = 1;
        }
    }
    for(int i = 0;i<8;i++) {
        if(i != column && board[row][i] != '.') {
            M[board[row][i]] = 1;
        }
    }
    int r = row-row%3;
    int c = column-column%3;
    for(int i = 0;i<3;i++) {
        for(int j = 0;j<3;j++) {
            if(r+i == row && c+j == column)
                continue;
            if(board[r+i][c+j] != '.') {
                M[board[r+i][c+j]] = 1;
            }
        }
    }
    return M;
}

bool subSolveSudoku(vector<vector<char> >& board, int row, int column) {
    if(row == 8)
        return true;
    map<char,bool> used = check(board, row, column);
    if(board[row][column] != '.') {
        if(used[board[row][column]] == 1)
            return false;
        if(column == 7)
            return subSolveSudoku(board, row+1, 0);
        else
            return subSolveSudoku(board, row, column+1);
    } else {
        for(int i = 1;i<=9;i++) {
            if(used[i] == 0) {
                board[row][column] = '0'+i;
                int newcolumn = column+1;
                int newrow = row;
                if(column == 7) {
                    newcolumn = 0;
                    newrow = row + 1;
                }
                if(subSolveSudoku(board, newrow, newcolumn)) {
                    return true;
                } else {
                    board[row][column] = '.';
                }
            }
        }
        return false;
    }
}


void solveSudoku(vector<vector<char> >& board) {
    subSolveSudoku(board,0,0);
}

int main() {
    int b = 1;
    vector<vector<char> > a(9,vector<char>(9,'.'));
    a[0][0] = '5';
    char c = a[0][0];
    a[0][1] = '3';
    a[0][4] = '7';
    a[1][0] = '6';
    a[1][3] = '1';
    a[1][4] = '9';
    a[1][5] = '5';
    a[2][1] = '9';
    a[2][2] = '8';
    a[2][7] = '6';
    a[3][0] = '8';
    a[3][4] = '6';
    a[3][8] = '3';
    a[4][0] = '4';
    a[4][3] = '8';
    a[4][5] = '3';
    a[4][8] = '1';
    a[5][0] = '7';
    a[5][4] = '2';
    a[5][8] = '6';
    a[6][1] = '6';
    a[6][6] = '2';
    a[6][7] = '8';
    a[7][3] = '4';
    a[7][4] = '1';
    a[7][5] = '9';
    a[7][8] = '5';
    a[8][4] = '8';
    a[8][7] = '7';
    a[8][8] = '9';

    solveSudoku(a);

    return 0;
}