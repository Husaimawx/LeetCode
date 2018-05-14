// memory limit exceed
class Solution {
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        if(s1 < s2)
            return 0;
        vector<int> temp(s2,-1);
        vector<vector<int>> res(s1,temp);
        for(int i = s1-s2+1;i<s1;i++)
            for(int j = 0;j<i-(s1-s2);j++)
                res[i][j] = 0;
        for(int i = s1-1;i>=0;i--)
        {
            if(s[i] == t[s2-1])
            {
                if(i == s1-1)
                {
                    res[i][s2-1] = 1;
                }
                else
                {
                    res[i][s2-1] = res[i+1][s2-1] + 1;
                }
            }
            else
            {
                if(i == s1-1)
                {
                    res[i][s2-1] = 0;
                }
                else
                {
                    res[i][s2-1] = res[i+1][s2-1];
                }
            }
        }
	    if(res[0][0] == -1)
		    subNum(s, t, 0, 0, res);
        return res[0][0];
    }
    
    void subNum(string s, string t, int sfrom, int tfrom, vector<vector<int>>& res)
    {
        int num1,num2;
        if(s[sfrom] == t[tfrom])
        {
            if(res[sfrom+1][tfrom+1] == -1)
                subNum(s,t,sfrom+1,tfrom+1,res);
            num2 = res[sfrom+1][tfrom+1];
        }
        else
            num2 = 0;
        if(res[sfrom+1][tfrom] == -1)
            subNum(s,t,sfrom+1,tfrom,res);
        num1 = res[sfrom+1][tfrom];
        res[sfrom][tfrom] = num1+num2;
    }
};

// accept, runtime beats 100.0% of cpp submissions
class Solution {
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        if(s1 < s2)
            return 0;
        vector<int> res(s2+1,0);
        res[s2] = 1;
        if(s[s1-1] == t[s2-1])
            res[s2-1] = 1;
        
        for(int i = s1-2;i>=0;i--)
        {
            for(int j = 0;j<s2;j++)
            {
                if(i-j>s1-s2)
                    res[j] = 0;
                else
                {
                    if(s[i] == t[j])
                    {
                        res[j] += res[j+1];
                    }
                }
            }
        }
        
        return res[0];
    }
};