class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        vector<pair<int,int>> max_list;
        vector<pair<int,int>> delete_list;
        
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == INT_MAX)
                    max_list.push_back(pair<int,int>(i,j));
            }
        }
        
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int t = 0;t<matrix[0].size();t++)
                    {
                        if(matrix[i][t] == INT_MAX)
                        {
                            delete_list.push_back(pair<int,int>(i,t));
                        }
                        else if(matrix[i][t] != 0)
                            matrix[i][t] = INT_MAX;
                    }
                    break;
                }
            }
        }

        for(int i = 0 ;i<matrix[0].size();i++)
        {
            for(int j = 0;j<matrix.size();j++)
            {
                if(matrix[j][i] == 0)
                {
                    for(int t = 0;t<matrix.size();t++)
                    {
                        if(matrix[t][i] == INT_MAX)
                        {
                            delete_list.push_back(pair<int,int>(t,i));
                        }
                        else if(matrix[t][i] != 0)
                            matrix[t][i] = INT_MAX;
                    }
                    break;
                }
            }       
        }
    
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == INT_MAX)
                    matrix[i][j] = 0;
            }
        }
        
        for(int i = 0;i<max_list.size();i++)
        {
            matrix[max_list[i].first][max_list[i].second] = INT_MAX;
        }
        
        for(int i = 0;i<delete_list.size();i++)
        {
            matrix[delete_list[i].first][delete_list[i].second] = 0;
        }
        
        return;
    }
};