class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        vector<int> temp(m,0);
        vector<vector<int>> res(n,temp);
        for(int i = 0;i<m;i++)
            res[n-1][i] = 1;
        for(int i = 0;i<n-1;i++)
            res[i][m-1] = 1;
        for(int i = n-2;i>=0;i--)
        {
            for(int j = m-2;j>=0;j--)
            {
                res[i][j] = res[i+1][j]+res[i][j+1];
            }
        }
        return res[0][0];
    }
};