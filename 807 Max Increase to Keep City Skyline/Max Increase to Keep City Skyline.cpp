class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> line(grid.size(),0);
        vector<int> column(grid[0].size(),0);
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                line[i] = max(line[i],grid[i][j]);
            }
        }
        
        for(int j = 0;j<grid[0].size();j++) {
            for(int i = 0;i<grid.size();i++) {
                column[j] = max(column[j],grid[i][j]);
            }
        }
        
        int res = 0;
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                res += min(line[i], column[j])-grid[i][j];
            }
        }
        return res;
    }
};