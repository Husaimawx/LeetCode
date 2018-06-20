class Solution {
public:
    int sz1;
    int sz2;
    vector<vector<bool>> flag;
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;
        
        sz1 = board.size();
        sz2 = board[0].size();
        vector<bool> temp(sz2,false);
        for(int i = 0;i<sz1;i++)
        {
            flag.push_back(temp);
        }
        
        for(int i = 0;i<sz1;i++)
        {
            for(int j = 0;j<sz2;j++)
            {
                if(board[i][j] == word[0])
                {
                    flag[i][j] = true;
                    if(existAux(board, word, 1, i, j))
                        return true;
                    flag[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool existAux(vector<vector<char>>& board, string word, int start, int x, int y)
    {
        if(start == word.size())
            return true;
        
        if(x>0 && flag[x-1][y] == false && board[x-1][y] == word[start])
        {
            flag[x-1][y] = true;
            if(existAux(board, word, start+1, x-1, y))
                return true;
            flag[x-1][y] = false;
        }
        if(x<sz1-1 && flag[x+1][y] == false && board[x+1][y] == word[start])
        {
            flag[x+1][y] = true;
            if(existAux(board, word, start+1, x+1, y))
                return true;
            flag[x+1][y] = false;            
        }
        if(y>0 && flag[x][y-1] == false && board[x][y-1] == word[start])
        {
            flag[x][y-1] = true;
            if(existAux(board, word, start+1, x, y-1))
                return true;
            flag[x][y-1] = false;                
        }
        if(y<sz2-1 && flag[x][y+1] == false && board[x][y+1] == word[start])
        {
            flag[x][y+1] = true;
            if(existAux(board, word, start+1, x, y+1))
                return true;
            flag[x][y+1] = false;                 
        }
        return false;
    }
};