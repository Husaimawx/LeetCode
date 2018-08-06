class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> res(s.size()+1,-1);
        res[s.size()] = 1;
        return wordBreakAux(s, wordDict, 0, res);
    }
    
    bool wordBreakAux(string s, vector<string>& wordDict, int from, vector<int>& res) {
        if(from == s.size())
            return true;
        
        for(auto item : wordDict)
        {
            if(ishead(s.substr(from), item))
            {
                if(res[from+item.size()] == -1)
                {
                    if(wordBreakAux(s, wordDict, from+item.size(), res))
                    {
                        res[from] = 1;
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if(res[from+item.size()] == 1)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
        }
        
        res[from] = 0;
        return false;
    }
    
    bool ishead(string s, string p)
    {
        if(s.size() < p.size())
            return false;
        
        for(int i = 0;i<p.size();i++)
        {
            if(s[i] != p[i])
                return false;
        }
        
        return true;
    }
};