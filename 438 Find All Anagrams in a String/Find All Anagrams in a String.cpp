class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size())
            return res;
        
        unordered_map<int,int> mask;
        unordered_map<int,int> value;
        for(int i = 0;i<26;i++)
        {
            mask[i] = 0;
            value[i] = 0;
        }
        
        for(int i = 0;i<p.size();i++)
        {
            mask[p[i]-'a'] += 1;
            value[s[i]-'a'] += 1;
        }
        int diff = s.size()-p.size();
        int dis = 0;
        for(int i = 0;i<26;i++)
        {
            dis += abs(mask[i]-value[i]);
        }
        for(int i = 0;i<=diff;i++)
        {
            if(dis == 0)
                res.push_back(i);
            if(i != diff)
            {
                if(value[s[i]-'a'] <= mask[s[i]-'a'])
                    dis += 1;
                else
                    dis -= 1;
                value[s[i]-'a']-=1;
                
                if(value[s[i+p.size()]-'a'] < mask[s[i+p.size()]-'a'])
                    dis -= 1;
                else
                    dis += 1;
                value[s[i+p.size()]-'a'] += 1;
            }
        }
        return res;
    }
    
    bool testEqual(unordered_map<int,int>& mask, unordered_map<int,int>& value)
    {
        for(auto iter = mask.begin();iter != mask.end();iter++)
        {
            if(value.count(iter->first) == 0 || value[iter->first] != iter->second)
                return false;
        }
        return true;
    }
};