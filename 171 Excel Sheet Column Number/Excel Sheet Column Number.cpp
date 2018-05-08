class Solution {
public:
    int titleToNumber(string s) {
        int num = 1;
        int res = 1;
        for(int i = 0;i < s.size()-1;i++)
        {
            num*=26;
            res += num;
        }
        for(int i = 0;i < s.size();i++)
        {
            res += (s[i]-'A')*num;
            num/=26;
        }
        return res;
    }
};