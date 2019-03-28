class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<int> temp(N,1);
        vector<vector<int>> pad(N, temp);
        for(auto item : mines) {
            pad[item[0]][item[1]] = 0;
        }

        vector<vector<int>> line(pad);
        for(int i = 0;i<N;i++) {
            int from = 0;
            for(int j = 0;j<N+1;j++) {
                if(j == N || pad[i][j] == 0) {
                    int to = j-1;
                    if (from > to) {
                        from = j + 1;
                        continue;
                    }

                    for(int k = from;k<=(from+to)/2;k++) {
                        line[i][k] = k-from+1;
                        line[i][from+to-k] = line[i][k];
                    }

                    from = j+1;
                    continue;
                }
            }
        }
        
        int res = 0;

        for(int i = 0;i<N;i++) {
            int from = 0;
            for(int j = 0;j<N+1;j++) {
                if(j == N || pad[j][i] == 0) {
                    int to = j-1;
                    if (from > to) {
                        from = j + 1;
                        continue;
                    }
                    
                    for(int k = from;k<=(from+to)/2;k++) {
                        res = max(res, min(line[k][i], k-from+1));
                        res = max(res, min(line[from+to-k][i], k-from+1));
                    }

                    from = j+1;
                    continue;
                }
            }
        }
        return res;
    }
};