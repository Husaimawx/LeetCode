class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return triangle[0][0];
        vector<int> res = triangle[size-1];
        
        for(int i = size-2;i>=0;i--)
        {
            for(int j = 0; j<=i; j++)
            {
                res[j] = triangle[i][j]+min(res[j],res[j+1]);
            }
        }
        return res[0];
    }
};