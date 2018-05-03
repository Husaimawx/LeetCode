class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      	int xsize = grid.size();
        if (xsize == 0)
            return 0;
        int ysize = grid[0].size();
        if (ysize == 0)
            return 0;

        vector<int> temp(ysize, INT_MAX);
        vector<vector<int>> ans(xsize, temp);
        ans[xsize - 1][ysize - 1] = grid[xsize - 1][ysize - 1];

        int sum = xsize + ysize - 3;
        int from, to, y;

        for (; sum >= 0; sum--)
        {
            if (ysize - 1 >= sum)
                from = 0;
            else
                from = sum - (ysize - 1);

            if (xsize - 1 >= sum)
                to = sum;
            else
                to = xsize - 1;

            for (int i = from; i<=to; i++)
            {
                y = sum - i;
                if (i + 1<xsize && ans[i + 1][y] != INT_MAX)
                {
                    ans[i][y] = ans[i + 1][y]+grid[i][y];   
                }
                if (y + 1<ysize && ans[i][y + 1] != INT_MAX)
                {
                    ans[i][y] = min(ans[i][y], ans[i][y+1]+grid[i][y]);  
                }
            }
        }

        return ans[0][0];  
    }
};