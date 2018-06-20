class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        if(s.size() == 0)
            return res;
        
        if(check(s))
        {
            temp.push_back(s);
            res.push_back(temp);
        }

        if(s.size() == 1)
        {
            return res;
        }
    
        for(int i = 1;i<s.size();i++)
        {
            string aux = s.substr(i);
            if(!check(aux))
                continue;
            string pre = s.substr(0,i);
            vector<vector<string>> subres = partition(pre);
            for(int i = 0;i<subres.size();i++)
            {
                subres[i].push_back(aux);
                res.push_back(subres[i]);
            }
        }
        return res;
    }
    
    bool check(string s)
    {
        for(int i = 0;i<s.size()/2;i++)
        {
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
};