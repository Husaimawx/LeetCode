class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int hashmap[9];
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
                hashmap[j] = 0;
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(hashmap[board[i][j]-'1']!=0)
                        return false;
                    hashmap[board[i][j]-'1'] = 1;
                }
            }
        }
        
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
                hashmap[j] = 0;
            for(int j = 0;j<9;j++)
            {
                if(board[j][i] != '.')
                {
                    if(hashmap[board[j][i]-'1']!=0)
                        return false;
                    hashmap[board[j][i]-'1'] = 1;
                }
            }
        }
        
        int multiline,multicol;
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
                hashmap[j] = 0;
            multiline = (i/3)*3;
            multicol = (i%3)*3;
            for(int j = 0;j<9;j++)
            {
                if(board[j/3+multiline][j%3+multicol] != '.')
                {
                    if(hashmap[board[j/3+multiline][j%3+multicol]-'1']!=0)
                        return false;
                    hashmap[board[j/3+multiline][j%3+multicol]-'1'] = 1;
                }
            }
        }
        
        return true;
    }
};