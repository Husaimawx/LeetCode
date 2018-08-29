class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> res(m+1,vector<int>(n+1,0));
        
        for(int i = 0;i<strs.size();i++)
        {
            int num0 = 0;
            int num1 = 0;
            for(int j = 0;j<strs[i].size();j++)
            {
                if(strs[i][j] == '0')
                    num0++;
                else
                    num1++;
            }
            for(int j = m;j>=num0;j--)
            {
                for(int t = n;t>=num1;t--)
                {
                    res[j][t] = max(res[j][t], res[j-num0][t-num1]+1);
                }
            }
        }
        return res[m][n];
    }
};