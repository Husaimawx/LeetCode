// Time Limit Exceeded

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchAux(s,p,0,0);
    }
    
    bool isMatchAux(string s, string p, int froms, int fromp)
    {
        if(fromp == p.size())
        {
            return (froms==s.size());
        }
        if(froms >= s.size())
        {
            for(int i = fromp;i<p.size();i++)
                if(p[i]!='*')
                    return false;
            return true;
        }
        
        if(p[fromp] == '?')
            return isMatchAux(s,p,froms+1,fromp+1);
        else if(p[fromp] == '*')
        {
            if(fromp!=p.size()-1 && p[fromp+1] == '*')
                return isMatchAux(s,p,froms,fromp+1);
            for(int i = froms;i<=s.size();i++)
            {
                if(isMatchAux(s,p,i,fromp+1))
                    return true;
            }
            return false;
        }
        else
        {
            if(s[froms] == p[fromp])
                return isMatchAux(s,p,froms+1,fromp+1);
            else
                return false;
        }
    }
};

// Other People's Solution

bool isMatch(string s, string p) {
	vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
	dp[0][0] = true;
	
	for(int j=1; j<=p.size(); j++)
	{
		if(p[j-1]=='*')
			dp[0][j] = true;
		else
			break;
	}
	
	for (int i=1; i<=s.size(); i++)
	{
		for (int j=1; j<=p.size(); j++)
		{
			if (s[i-1] == p[j-1] || p[j-1] == '?')
				dp[i][j] = dp[i-1][j-1];
			else if (p[j-1] == '*')
				dp[i][j] = dp[i][j-1] || dp[i-1][j];
		}
	}
	
	return dp.back().back();
}

// My Solution
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        
        int fromp = p.size();
        for(int i = 0;i<s.size();i++)
            dp[i][fromp] = 0;
        dp[s.size()][fromp] = 1;
        
        int froms = s.size();
        int i;
        for(i = p.size();i>=0;i--)
        {
            if(i != p.size() && p[i]!='*')
                break;
            dp[froms][i] = 1;
        }
        for(;i>=0;i--)
        {
            dp[froms][i] = 0;
        }
            
        isMatchAux(s,p,0,0,dp);
        if(dp[0][0] == 0)
            return false;
        return true;
    }
    
    void isMatchAux(string s, string p, int froms, int fromp, vector<vector<int>>& dp)
    {
        if(dp[froms][fromp]!=-1)
            return;

        if(p[fromp] == '?')
        {
            isMatchAux(s,p,froms+1,fromp+1,dp);
            dp[froms][fromp] = dp[froms+1][fromp+1];
        }
        else if(p[fromp] == '*')
        {
            if(fromp!=p.size()-1 && p[fromp+1] == '*')
            {
                isMatchAux(s,p,froms,fromp+1,dp);
                dp[froms][fromp] = dp[froms][fromp+1];
                return;
            }
            for(int i = froms;i<=s.size();i++)
            {
                isMatchAux(s,p,i,fromp+1,dp);
                if(dp[i][fromp+1] == 1)
                {
                    dp[froms][fromp] = 1;
                    break;
                }
                dp[froms][fromp] = 0;
            }
        }
        else
        {
            if(s[froms] == p[fromp])
            {
                isMatchAux(s,p,froms+1,fromp+1,dp);
                dp[froms][fromp] = dp[froms+1][fromp+1];
            }
            else
                dp[froms][fromp] = 0;
        }
    }
};

// very good solution
isMatch(s, p) = isMatch(s, p + 1) || isMatch(s + 1, p + 1) || ... || isMatch(s + n, p+1)
= isMatch(s, p + 1) || isMatch(s + 1, p)

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_long = s.size(), p_long = p.size();
        int i = 0 ,j = 0;
        int match;
        int risk = -1;
        while (i < s_long) {
            if (j < p_long && p[j] == '*') {
                match = i;
                risk = j++;
            }
            else if (j < p_long && (p[j] == s[i] || p[j] == '?')) {
                ++i;
                ++j;
            }
            else if (risk >= 0) {
                i = ++match;
                j = risk + 1;
            }
            else return false;
        }
        while (j < p_long && p[j] == '*') ++j;
        return j == p_long;
    }
};