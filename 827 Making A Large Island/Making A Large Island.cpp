class Solution {
    int m;
    int n;
    vector<int> pos{-1,0,1,0,-1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        map<pair<int,int>,int> M;
        map<int,int> sum;
        
        int index = 1;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1 && M.count(pair<int,int>(i,j)) == 0) {
                    int temp = M.size();
                    DFS(grid,i,j,M, index);
                    sum[index] = M.size()-temp;
                    index += 1;
                }
            }
        }
        /*
        for(int i = 0;i<2;i++) {
            for(int j = 0;j<2;j++) {
                cout << M[pair<int,int>(i,j)] << endl;
            }
        }*/
        //cout << sum[1] << sum[2];
        
        int res = 0;
        for(int i = 1;i<index;i++)
            res = max(res, sum[i]);

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 0) {
                    int temp = 1;
                    map<int,int> indexs;
                    for(int t = 0;t<4;t++) {
                        if(check(i+pos[t],j+pos[t+1]) && grid[i+pos[t]][j+pos[t+1]] == 1 && indexs.count(M[pair<int,int>(i+pos[t],j+pos[t+1])]) == 0) {
                            indexs[M[pair<int,int>(i+pos[t],j+pos[t+1])]] = 1;
                            temp += sum[M[pair<int,int>(i+pos[t],j+pos[t+1])]];
                            //cout << i+pos[t] << j+pos[t+1] << endl;
                        }
                    }
                    res = max(res, temp);
                }
            }
        }
        return res;
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j, map<pair<int,int>,int>& M, int index) {
        //if(M.count(pair<int,int>(i,j)) != 0)
        //    return;
        M[pair<int,int>(i,j)] = index;
        
        for(int t = 0;t<4;t++) {
            if(check(i+pos[t],j+pos[t+1]) && grid[i+pos[t]][j+pos[t+1]] == 1 && M.count(pair<int,int>(i+pos[t],j+pos[t+1])) == 0)
               DFS(grid, i+pos[t], j+pos[t+1], M, index);
        }
        return;
    }
    
    bool check(int i, int j) {
        return(i >= 0 && j>=0 && i<m && j<n);
    }
};