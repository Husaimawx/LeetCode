class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int x = matrix.size();
        if(x == 0)
            return 0;
        int y = matrix[0].size();
        if(y == 0)
            return 0;
        
        vector<int> res(x,0);
        int max = 0;
        for(int i = y-1;i>=0;i--)
        {
            if(matrix[x-1][i] == '1')
            {
                res[x-1] = 1;
                if(max == 0)
                    max = 1;
            }
            else
                res[x-1] = 0;
            
            
            for(int j = x-2;j>=0;j--)
            {
                if(matrix[j][i] == '0')
                {
                    res[j] = 0;
                    continue;
                }
                
                if(max == 0)
                    max = 1;
                
                if(res[j]==res[j+1])
                {
                    if(res[j] == 0)
                    {
                        res[j] = 1;
                    }
                    else
                    {
                        if(matrix[j+res[j]][i+res[j]] == '1')
                        {
                            res[j] += 1;
                            if(res[j] > max)
                                max = res[j];
                        }
                    }
                }
                else if(res[j]<res[j+1])
                {
                    res[j] += 1;
                }
                else
                {
                    res[j] = res[j+1]+1;
                }
            }
        }
        
        return (max*max);
    }
};