class Solution {
public:
    int finished;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int> temp(matrix[0].size(),0);
        vector<vector<int>> res(matrix.size(),temp);
        finished = matrix.size()*matrix[0].size();
        
        while(finished != 0) {
            for(int i = 0;i<matrix.size();i++) {
                for(int j = 0;j<matrix[0].size();j++) {
                    if(res[i][j] == 0) {
                        longestIncreasingPathAux(matrix, res, i,j); 
                    }
                }
                if(finished == 0)
                    break;
            }
        }
        
        int maxres = 0;
        for(int i = 0;i<matrix.size();i++) {
            for(int j = 0;j<matrix[0].size();j++) {
                maxres = max(maxres,res[i][j]);
            }
        }
        return maxres;
    }
    
    void longestIncreasingPathAux(vector<vector<int>>& matrix, vector<vector<int>>& res, int x, int y) {
        if (x>0 && matrix[x][y]>matrix[x - 1][y]) {
            if (res[x - 1][y] == 0)
                longestIncreasingPathAux(matrix, res, x - 1, y);
            res[x][y] = max(res[x][y], res[x - 1][y] + 1);
        }
        if (x<matrix.size() - 1 && matrix[x][y]>matrix[x + 1][y]) {
            if (res[x + 1][y] == 0)
                longestIncreasingPathAux(matrix, res, x + 1, y);
            res[x][y] = max(res[x][y], res[x + 1][y] + 1);
        }
        if (y>0 && matrix[x][y]>matrix[x][y - 1]) {
            if (res[x][y - 1] == 0)
                longestIncreasingPathAux(matrix, res, x, y - 1);
            res[x][y] = max(res[x][y], 1 + res[x][y - 1]);
        }
        if (y<matrix[0].size() - 1 && matrix[x][y]>matrix[x][y + 1]) {
            if (res[x][y + 1] == 0)
                longestIncreasingPathAux(matrix, res, x, y + 1);
            res[x][y] = max(res[x][y], 1 + res[x][y + 1]);
        }
        if (res[x][y] == 0)
            res[x][y] = 1;
        finished--;
        return;
    }
};