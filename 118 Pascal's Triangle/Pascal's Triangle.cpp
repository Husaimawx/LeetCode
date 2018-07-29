class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        if(numRows == 0)
            return res;
        
        vector<int> line(1,1);
        res.push_back(line);
        
        for(int i = 2; i<=numRows; i++)
        {
            vector<int> line(i,1);
            for(int j = 1;j<i-1;j++)
            {
                line[j] = res[i-2][j-1]+res[i-2][j];
            }
            res.push_back(line);
        }
        
        return res;
    }
};