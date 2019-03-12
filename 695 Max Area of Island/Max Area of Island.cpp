class Solution {
    int M;
    int N;
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        M = grid.size();
        N = grid[0].size();
        vector<int> adj({1,0,-1,0,1});
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                //cout << grid[0][0] << grid[0][1] << grid[0][2] << grid[1][0] << grid[1][1] << grid[1][2] << endl;
                if(grid[i][j] == 0)
                    continue;
                int tempres = 1;
                vector<pair<int,int>> land(1, pair<int,int>(i,j));
                grid[i][j] = 0;
                int from = 0;
                while(from != land.size()) {
                    int to = land.size();
                    for(int r = from;r<to;r++) {
                        //cout << land[r].first << land[r].second << endl;
                        for(int t = 0;t<4;t++) {
                            if(check(land[r].first+adj[t],land[r].second+adj[t+1], grid)) {
                                tempres += 1;
                                grid[land[r].first+adj[t]][land[r].second+adj[t+1]] = 0;
                                land.push_back(pair<int,int>(land[r].first+adj[t],land[r].second+adj[t+1]));
                            }
                        }    
                        //cout << grid[0][0] << grid[0][1] << grid[0][2] << grid[1][0] << grid[1][1] << grid[1][2] << endl;
                    }
                    from = to;
                }

                if(tempres > res)
                    res = tempres;
            }
        }
        return res;
    }
    
    bool check(int i, int j, vector<vector<int>>& grid) {
        //cout <<'c'<< i << j << endl;
        if(i<0 || j<0)
            return false;
        if(i >= M || j >= N)
            return false;
        return grid[i][j];
    }
};