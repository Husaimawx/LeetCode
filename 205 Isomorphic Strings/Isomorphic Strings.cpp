class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s1(128,-1);
        for(int i = 0;i<s.size();i++)
        {
            if(s1[s[i]] == -1)
                s1[s[i]] = t[i];
            else
            {
                if(s1[s[i]] != t[i])
                    return false;
            }
        }
        vector<int> t1(128,-1);
        for(int i = 0;i<t.size();i++)
        {
            if(t1[t[i]] == -1)
                t1[t[i]] = s[i];
            else
            {
                if(t1[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};