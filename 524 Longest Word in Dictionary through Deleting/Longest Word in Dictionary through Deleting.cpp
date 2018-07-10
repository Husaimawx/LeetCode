class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        auto comp = [](const string& s1, const string& s2) {
            if(s1.size() > s2.size())
                return 1;
            if(s1.size() < s2.size())
                return 0;
            for(int i = 0;i<s1.size();i++)
            {
                if(s1[i] < s2[i])
                    return 1;
                else if(s1[i] > s2[i])
                    return 0;
            }
            return 1;
        };
        
        if(d.size() == 0)
            return "";
        
        sort(d.begin(), d.end(), comp);
        for(int i = 0;i<d.size();i++)
        {
            if(contain(s, d[i]))
                return d[i];
        }
        return "";
    }
    
    bool contain(string s, string pattern)
    {
        int i, j = 0;
        for(i = 0;i<s.size();i++)
        {
            if(s[i] == pattern[j])
            {
                j++;
                if(j == pattern.size())
                    return 1;
            }
        }
        
        return 0;
    }
};