class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 1;
        
        vector<vector<bool>> isPalin(s.size(),vector<bool>(s.size(),false));
        
        int res = 0;
        for(int i = 0;i<s.size();i++)
        {
            for(int j = i;j>=0;j--)
            {
                if(j == i)
                {
                    isPalin[i][j] = true;
                    res++;
                }
                else if(j == i-1)
                {
                    if(s[i]==s[j])
                    {
                        isPalin[j][i] = true;
                        res++;                        
                    }
                }
                else
                {
                    if(s[i] == s[j] && isPalin[j+1][i-1])
                    {
                        isPalin[j][i] = true;
                        res++;                           
                    }
                }
            }
        }
        return res;
    }
};