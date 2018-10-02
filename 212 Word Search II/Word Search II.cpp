class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> tempword(words.begin(), words.end());
        vector<string> word(tempword.begin(),tempword.end());
        words = word;
        
        vector<string> res;
        if(board.size() == 0 || board[0].size() == 0)
            return res;
        vector<vector<char>> newboard(board.size()+2,vector<char>(board[0].size()+2,'1'));
        for(int i = 1;i<=board.size();i++)
        {
            for(int j = 1;j<=board[0].size();j++)
            {
                newboard[i][j] = board[i-1][j-1];
            }
        }
        for(int i = 0;i<words.size();i++)
        {
            if(findSingleWords(newboard, words[i]))
                res.push_back(words[i]);
        }
        return res;
    }
    
    bool findSingleWords(vector<vector<char>>& board, string& word)
    {
        for(int i = 1;i<board.size()-1;i++)
        {
            for(int j = 1;j<board[0].size()-1;j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> bit(board.size(),vector<bool>(board[0].size(),true));
                    bit[i][j] = false;
                    if(findSingleWordsAux(board, word,i,j,1,bit))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool findSingleWordsAux(vector<vector<char>>& board, string& word, int x, int y, int from, vector<vector<bool>>& bit)
    {
        if(from == word.size())
            return true;
        if(bit[x-1][y] == true && board[x-1][y] == word[from])
        {
            bit[x-1][y] = false;
            bool res = findSingleWordsAux(board,word,x-1,y,from+1,bit);
            bit[x-1][y] = true;
            if(res)
                return true;   
        }
        if(bit[x+1][y] == true && board[x+1][y] == word[from])
        {
            bit[x+1][y] = false;
            bool res = findSingleWordsAux(board,word,x+1,y,from+1,bit);
            bit[x+1][y] = true;
            if(res)
                return true;   
        }
        if(bit[x][y-1] == true && board[x][y-1] == word[from])
        {
            bit[x][y-1] = false;
            bool res = findSingleWordsAux(board,word,x,y-1,from+1,bit);
            bit[x][y-1] = true;
            if(res)
                return true;   
        }
        if(bit[x][y+1] == true && board[x][y+1] == word[from])
        {
            bit[x][y+1] = false;
            bool res = findSingleWordsAux(board,word,x,y+1,from+1,bit);
            bit[x][y+1] = true;
            if(res)
                return true;   
        }

        return false;
    }
};