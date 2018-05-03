// exceed time limit
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int xsize = obstacleGrid.size();
        if(xsize == 0)
            return 0;
        int ysize = obstacleGrid[0].size();
        if(ysize == 0)
            return 0;
        if(obstacleGrid[0][0] == 1)
            return 0;
        return tempuniquePathsWithObstacles(obstacleGrid,0,0);
    }
    
    int tempuniquePathsWithObstacles(vector<vector<int>>& obstacleGrid, int xnow, int ynow) {
        if(xnow == obstacleGrid.size()-1 && ynow == obstacleGrid[0].size()-1)
            return 1-obstacleGrid[xnow][ynow];
        int way1 = 0, way2 = 0;
        if(xnow != obstacleGrid.size()-1 && obstacleGrid[xnow+1][ynow] == 0)
        {
            way1 = tempuniquePathsWithObstacles(obstacleGrid,xnow+1,ynow);
        }
        if(ynow != obstacleGrid[0].size()-1 && obstacleGrid[xnow][ynow+1] == 0)
        {
            way2 = tempuniquePathsWithObstacles(obstacleGrid,xnow,ynow+1);
        }
        return way1+way2;
    }
};

//good solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int xsize = obstacleGrid.size();
        if(xsize == 0)
            return 0;
        int ysize = obstacleGrid[0].size();
        if(ysize == 0)
            return 0;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[xsize-1][ysize-1] == 1)
            return 0;
        
        vector<int> temp(ysize,0);
        vector<vector<int>> ans(xsize,temp);
        ans[xsize-1][ysize-1] = 1;
        
        int sum = xsize+ysize-3;
        int from,to,y;
        for(;sum>=0;sum--)
        {
            if(ysize-1 >= sum)
                from = 0;
            else
                from = sum-(ysize-1);
            
            if(xsize-1 >= sum)
                to = sum;
            else
                to = xsize-1;
            
            for(int i = from; i<=to; i++)
            {
                y = sum-i;
                if(i+1<xsize && obstacleGrid[i+1][y] == 0)
                    ans[i][y] += ans[i+1][y];
                if(y+1<ysize && obstacleGrid[i][y+1] == 0)
                    ans[i][y] += ans[i][y+1];
            }
        }
        
        return ans[0][0];
    }
};