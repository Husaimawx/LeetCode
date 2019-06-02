class Solution {
    int res = 6;
public:
    int findMinStep(string board, string hand) {
        map<char,int> remain;
        for(int i = 0;i<hand.size();i++) {
            remain[hand[i]] += 1;
        }
        
        dfs(board, remain, 0);
        return res == 6 ? -1 : res;
    }
    
    void dfs(string& board, map<char,int>& remain, int count) {
        //cout << board << endl;
        if(board.size() == 0) {
            res = min(res, count);
            return;
        }
        if(count > res)
            return;
        int cnt = 1;
        for(int i = 1;i<=board.size();i++) {
            if(i == board.size() || board[i] != board[i-1]) {
                if(cnt == 1 && remain[board[i-1]] >= 2) {
                    string temp = board.substr(0,i-1)+board.substr(i,board.size()-i);
                    simplify(temp);
                    remain[board[i-1]] -= 2;
                    dfs(temp, remain, count+2);
                    remain[board[i-1]] += 2;
                }    
                if(cnt == 2 && remain[board[i-1]] >= 1) {
                    string temp = board.substr(0,i-2)+board.substr(i,board.size()-i);
                    simplify(temp);
                    remain[board[i-1]] -= 1;
                    dfs(temp, remain, count+1);
                    remain[board[i-1]] += 1;
                }  
                cnt = 1;
            }
            else {
                cnt += 1;                
            }
        }
    }
    
    void simplify(string& board) {
        //cout << "-------" << endl;
        //cout << board << endl;
        while(1) {
            int cnt = 1;
            string res = "";
            for(int i = 1;i<=board.size();i++) {
                if(i == board.size() || board[i] != board[i-1]) {
                    if(cnt == 1) {
                        res = res + board[i-1];
                    } else if(cnt == 2) {
                        res = res + board[i-1];
                        res = res + board[i-1];
                    }
                    cnt = 1;
                } else {
                    cnt += 1;
                }
            }
            if(board.size() == res.size())
                return;
            else
                board = res;
        }
        //cout << board << endl;
        //cout << "-------" << endl;
    }
};