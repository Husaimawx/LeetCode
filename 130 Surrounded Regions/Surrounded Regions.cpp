class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int bs1 = board.size();
        if(bs1 < 3)
            return;
        
        int bs2 = board[0].size();
        if(bs2 < 3)
            return;       
        
        deque<pair<int,int>> dq;
        
        for(int i = 0;i<bs1;i++)
        {
            if(board[i][0] == 'O')
            {
                board[i][0] = '1';
                dq.push_back(pair<int,int>(i,0));
            }
            if(board[i][bs2-1] == 'O')
            {
                board[i][bs2-1] = '1';
                dq.push_back(pair<int,int>(i,bs2-1));
            }
        }
        
        for(int i = 0;i<bs2;i++)
        {
            if(board[0][i] == 'O')
            {
                board[0][i] = '1';
                dq.push_back(pair<int,int>(0,i));
            }
            if(board[bs1-1][i] == 'O')
            {
                board[bs1-1][i] = '1';
                dq.push_back(pair<int,int>(bs1-1,i));
            }
        }

        pair<int,int> temp;
        while(!dq.empty())
        {
            temp = dq.front();
            dq.pop_front();
            if(temp.first > 0 && board[temp.first-1][temp.second] == 'O')
            {
                board[temp.first-1][temp.second] = '1';
                dq.push_back(pair<int,int>(temp.first-1,temp.second));
            }
            if(temp.first < bs1-1 && board[temp.first+1][temp.second] == 'O')
            {
                board[temp.first+1][temp.second] = '1';
                dq.push_back(pair<int,int>(temp.first+1,temp.second));
            }
            if(temp.second > 0 && board[temp.first][temp.second-1] == 'O')
            {
                board[temp.first][temp.second-1] = '1';
                dq.push_back(pair<int,int>(temp.first,temp.second-1));
            }
            if(temp.second < bs2-1 && board[temp.first][temp.second+1] == 'O')
            {
                board[temp.first][temp.second+1] = '1';
                dq.push_back(pair<int,int>(temp.first,temp.second+1));
            }
        }
        
        for(int i = 0;i<bs1;i++)
        {
            for(int j = 0;j<bs2;j++)
            {
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};