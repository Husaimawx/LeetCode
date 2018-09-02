class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26,0);
        int from = 0;
        int max = 0;
        int res = 0;
        for(int i = 0;i<s.size();i++)
        {
            num[s[i]-'A']++;
            max = max >= num[s[i]-'A'] ? max : num[s[i]-'A'] ;
            while(i-from+1-max > k)
            {
                num[s[from]-'A']--;
                from++;
                max = 0;
                for(int j = 0;j<26;j++)
                {
                    if(num[j]>max)
                        max = num[j];
                }
            }
            res = res >= i-from+1 ? res : i-from+1;
        }
        return res;
    }
};