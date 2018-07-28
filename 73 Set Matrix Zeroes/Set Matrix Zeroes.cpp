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


My idea is simple: store states of each row in the first of that row, and store states of each column in the first of that column. Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. In the first phase, use matrix elements to set states in a top-down way. In the second phase, use states to set matrix elements in a bottom-up way.

void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}