class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int remain = 0;
        vector<pair<int,int>> v;
        
        for(int i = 0;i<grid.size();i++) {
            for(int j = 0;j<grid[0].size();j++) {
                if(grid[i][j] == 1)
                    remain += 1;
                else if(grid[i][j] == 2) {
                    v.push_back(pair<int,int>(i,j));
                }
            }
        }
        
        vector<int> near{-1,0,1,0,-1};
        int from = 0;
        int level = 0;
        while(from != v.size()) {
            if(remain == 0)
                return level;
            int to = v.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<4;j++) {
                    int x = v[i].first+near[j];
                    int y = v[i].second+near[j+1];
                    if(x>=0 && y >=0 && x < grid.size() && y <grid[0].size() && grid[x][y] == 1) {
                        v.push_back(pair<int,int>(x,y));
                        grid[x][y] = 2;
                        remain -= 1;
                    }
                }
            }
            from = to;
            level += 1;
        }
        if(remain == 0)
            return level;
        return -1;
    }
};