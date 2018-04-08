class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxnum = 1;
        int length = 1;
        int takeUp[200] = {0};
        takeUp[s[0]] = 1;
        
        if(s.length() == 0)
            return 0;
        
        int from = 0;
        for(int to = 1;to < s.length();to++)
        {
            if(takeUp[s[to]] == 0)
            {
                takeUp[s[to]] = 1;   
                length++;
                if(length > maxnum)
                {
                    maxnum = length;
                }
            }
            else
            {
                while(1)
                {
                    if(s[from] == s[to])
                    {
                        length = to-from;
                        from++;
                        break;
                    }
                    else
                    {
                        takeUp[s[from]] = 0;
                        from++;
                    }
                }
            }
        }
        return maxnum;
    }
};