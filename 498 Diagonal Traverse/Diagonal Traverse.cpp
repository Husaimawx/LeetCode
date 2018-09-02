class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int order = 1;
        for(int i = 0;i<=m+n-2;i++)
        {
            int from = max(0,i-(m-1));
            int to = min(n-1,i);
            if(order)
            {
                for(int j = from;j<=to;j++)
                {
                    res.push_back(matrix[i-j][j]);
                }
            }
            else
            {
                for(int j = to;j>=from;j--)
                {
                    res.push_back(matrix[i-j][j]);
                }                
            }
            order = 1-order;
        }
        return res;
    }
};