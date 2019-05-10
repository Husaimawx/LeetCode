class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int remain = 0;
        int x = 0;
        int y = 0;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 0)
                    remain += 1;
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        int res = dfs(grid,x,y,remain);
        return res;
    }
    
    int dfs(vector<vector<int>>& grid,int x,int y,int remain) {
        vector<int> dir{-1,0,1,0,-1};
        if(grid[x][y] == 2) {
            if(remain == 0)
                return 1;
            return 0;
        }
        int res = 0;
        for(int i = 0;i<4;i++) {
            int newx = x+dir[i];
            int newy = y+dir[i+1];
            if(newx < 0 || newy < 0 || newx >= grid.size() || newy >= grid[0].size() || abs(grid[newx][newy]) == 1)
                continue;
            
            if(grid[newx][newy] == 0) {
                grid[newx][newy] = 1;
                remain -= 1;
                res += dfs(grid,newx,newy,remain);
                grid[newx][newy] = 0;
                remain += 1;
            }
            else
                res += dfs(grid,newx,newy,remain);
        }
        return res;
    }
};