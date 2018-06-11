class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuAux(board, 0, 0);
        return;
    }

    bool solveSudokuAux(vector<vector<char>>& board, int x, int y)
    {
        if(x == 9)
            return true;
        
        if(board[x][y] != '.')
        {
            if(y == 8)
            {
                y = 0;
                x++;
            }
            else
                y++;
            return solveSudokuAux(board, x, y);
        }
        
        int valid[9] = {1,1,1,1,1,1,1,1,1};
        checkValid(board,x,y,valid);
        int newx, newy;
        if(y == 8)
        {
            newy = 0;
            newx = x+1;
        }
        else
        {
            newx = x;
            newy = y+1;
        }
        for(int i = 0;i<9;i++)
        {
            if(valid[i] == 1)
            {
                board[x][y] = 49+i;
                if(solveSudokuAux(board, newx, newy))
                    return true;
            }
        }
        board[x][y] = '.';
        return false;
    }
    
    void checkValid(vector<vector<char>>& board, int x, int y, int* num)
    {
        for(int i = 0;i<9;i++)
        {
            if(board[x][i] != '.')
                num[board[x][i]-49] = 0;
            if(board[i][y] != '.')
                num[board[i][y]-49] = 0;
        }
        int basex = x-x%3;
        int basey = y-y%3;
        for(int i = basex;i<basex+3;i++)
        {
            for(int j = basey;j<basey+3;j++)
            {
                if(board[i][j] != '.')
                    num[board[i][j]-49] = 0;
            }
        }
        return;
    }
};