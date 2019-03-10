class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> step;
        step.push_back(vector<int>({1,2}));
        step.push_back(vector<int>({-1,2}));
        step.push_back(vector<int>({1,-2}));
        step.push_back(vector<int>({-1,-2}));
        step.push_back(vector<int>({2,1}));
        step.push_back(vector<int>({2,-1}));
        step.push_back(vector<int>({-2,1}));
        step.push_back(vector<int>({-2,-1}));
        vector<vector<double>> board(N, vector<double>(N,0)); 
        board[r][c] = 1;
        for(int i = 0;i<K;i++) {
            vector<vector<double>> board2(N, vector<double>(N,0)); 
            for(int j = 0;j<N;j++) {
                for(int t = 0;t<N;t++) {
                    for(int r = 0;r<8;r++) {
                        if(check(N,j+step[r][0],t+step[r][1]))
                            board2[j+step[r][0]][t+step[r][1]] += (board[j][t]/8);
                    }
                }
            }

            board = board2;
        }
        
        double res = 0;
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                res += board[i][j];
            }
        }
        return res;
    }
    
    bool check(int N, int x, int y) {
        if(x >= 0 && x < N && y >= 0 && y < N)
            return 1;
        return 0;
    }
};