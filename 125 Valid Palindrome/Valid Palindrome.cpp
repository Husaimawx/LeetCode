class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            if(!((s[i]<='z' && s[i]>='a') || (s[i]<='9' && s[i]>='0')))
            {
                i++;
                continue;
            }
            if(!((s[j]<='z' && s[j]>='a') || (s[j]<='9' && s[j]>='0')))
            {
                j--;
                continue;
            }
            
            if((s[i]-s[j]) != 0)
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};