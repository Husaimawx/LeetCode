class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> temp(matrix[0].size(),0);
        vector<vector<int>> pacific(matrix.size(),temp);
        vector<vector<int>> atlantic(matrix.size(),temp);
        
        queue<pair<int,int>> pac;
        for(int i = 0;i<n;i++)
        {
            pacific[0][i] = 1;
            pac.push(pair<int,int>(0,i));
        }
        for(int i = 0;i<m;i++)
        {
            pacific[i][0] = 1;
            pac.push(pair<int,int>(i,0));
        }
        while(pac.size() != 0)
        {
            pair<int,int> temp = pac.front();
            pac.pop();
            if(temp.first > 0)
            {
                if(pacific[temp.first-1][temp.second] == 0 && matrix[temp.first-1][temp.second] >= matrix[temp.first][temp.second])
                {
                    pacific[temp.first-1][temp.second] = 1;
                    pac.push(pair<int,int>(temp.first-1,temp.second));
                }
            }
            if(temp.first < m-1)
            {
                if(pacific[temp.first+1][temp.second] == 0 && matrix[temp.first+1][temp.second] >= matrix[temp.first][temp.second])
                {
                    pacific[temp.first+1][temp.second] = 1;
                    pac.push(pair<int,int>(temp.first+1,temp.second));
                }
            }
            if(temp.second > 0)
            {
                if(pacific[temp.first][temp.second-1] == 0 && matrix[temp.first][temp.second-1] >= matrix[temp.first][temp.second])
                {
                    pacific[temp.first][temp.second-1] = 1;
                    pac.push(pair<int,int>(temp.first,temp.second-1));
                }
            }
            if(temp.second < n-1)
            {
                if(pacific[temp.first][temp.second+1] == 0 && matrix[temp.first][temp.second+1] >= matrix[temp.first][temp.second])
                {
                    pacific[temp.first][temp.second+1] = 1;
                    pac.push(pair<int,int>(temp.first,temp.second+1));
                }
            }
        }
        
        queue<pair<int,int>> atl;
        for(int i = 0;i<n;i++)
        {
            atlantic[m-1][i] = 1;
            atl.push(pair<int,int>(m-1,i));
        }
        for(int i = 0;i<m;i++)
        {
            atlantic[i][n-1] = 1;
            atl.push(pair<int,int>(i,n-1));
        }
        while(atl.size() != 0)
        {
            pair<int,int> temp = atl.front();
            atl.pop();
            if(temp.first > 0)
            {
                if(atlantic[temp.first-1][temp.second] == 0 && matrix[temp.first-1][temp.second] >= matrix[temp.first][temp.second])
                {
                    atlantic[temp.first-1][temp.second] = 1;
                    atl.push(pair<int,int>(temp.first-1,temp.second));
                }
            }
            if(temp.first < m-1)
            {
                if(atlantic[temp.first+1][temp.second] == 0 && matrix[temp.first+1][temp.second] >= matrix[temp.first][temp.second])
                {
                    atlantic[temp.first+1][temp.second] = 1;
                    atl.push(pair<int,int>(temp.first+1,temp.second));
                }
            }
            if(temp.second > 0)
            {
                if(atlantic[temp.first][temp.second-1] == 0 && matrix[temp.first][temp.second-1] >= matrix[temp.first][temp.second])
                {
                    atlantic[temp.first][temp.second-1] = 1;
                    atl.push(pair<int,int>(temp.first,temp.second-1));
                }
            }
            if(temp.second < n-1)
            {
                if(atlantic[temp.first][temp.second+1] == 0 && matrix[temp.first][temp.second+1] >= matrix[temp.first][temp.second])
                {
                    atlantic[temp.first][temp.second+1] = 1;
                    atl.push(pair<int,int>(temp.first,temp.second+1));
                }
            }
        }

        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    res.push_back(pair<int,int>(i,j));
                }
            }
        }
        return res;
    }
};