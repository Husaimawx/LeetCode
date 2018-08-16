class NumMatrix {
int flag = 0;
vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size() == 0)
            flag = 1;
        else
        {
            vector<int> temp(matrix[0].size()+1,0);
            for(int i = 0;i<matrix.size()+1;i++)
                sum.push_back(temp);

            for(int i = 0;i<matrix.size();i++)
            {
                sum[i+1][1] = matrix[i][0];
                for(int j = 1;j<matrix[0].size();j++)
                {
                    sum[i+1][j+1] = sum[i+1][j]+matrix[i][j];
                }
            }
            for(int j = 0;j<matrix[0].size();j++)
            {
                for(int i = 1;i<matrix.size();i++)
                {
                    sum[i+1][j+1] += sum[i][j+1];
                }
            }            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(flag == 1)
            return 0;
        return (sum[row2+1][col2+1]+sum[row1][col1]-sum[row2+1][col1]-sum[row1][col2+1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */