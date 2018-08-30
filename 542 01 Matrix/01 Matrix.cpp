class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;
        vector<vector<int>> res(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        queue<pair<int,int>> dq;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    res[i][j] = 0;
                    dq.push(pair<int,int>(i,j));
                }
            }
        }
        
        int level = 0;
        while(dq.size() != 0)
        {
            level++;
            int size = dq.size();
            for(int i = 0;i<size;i++)
            {            
                int m = dq.front().first;
                int n = dq.front().second;
                dq.pop();
                if(m>0 && res[m-1][n] == INT_MAX)
                {
                    res[m-1][n] = level;
                    dq.push(pair<int,int>(m-1,n));
                }
                if(m<matrix.size()-1 && res[m+1][n] == INT_MAX)
                {
                    res[m+1][n] = level;
                    dq.push(pair<int,int>(m+1,n));
                }
                if(n>0 && res[m][n-1] == INT_MAX)
                {
                    res[m][n-1] = level;
                    dq.push(pair<int,int>(m,n-1));
                }
                if(n<matrix[0].size()-1 && res[m][n+1] == INT_MAX)
                {
                    res[m][n+1] = level;
                    dq.push(pair<int,int>(m,n+1));
                }
            }
        }
        return res;
    }
};