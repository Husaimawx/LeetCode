class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0)
            return 0;
        vector<int> count(26,0);
        for(int i = 0;i<s.size();i++)
        {
            count[s[i]-'a']++;
        }
        
        int i;
        for(i = 0;i<26;i++)
        {
            if(count[i] == 0)
                continue;
            if(count[i]<k)
                break;
        }
        if(i == 26)
            return s.size();
        
        char split = 'a'+i;
        int from = 0;
        int res = 0;
        while(1)
        {
            int oldfrom = from;
            from = s.find(split, from);
            if(from != string::npos)
            {
                int temp = longestSubstring(s.substr(oldfrom, from-oldfrom),k);
                if(temp > res)
                    res = temp;
                from++;
            }
            else
            {
                int temp = longestSubstring(s.substr(oldfrom),k);
                if(temp > res)
                    res = temp;                
                break;
            }
        }
        return res;
    }
};