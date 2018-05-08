class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = -1;
        int i,j;
        for(i = s.size()-1;i>=0 && s[i] == ' ';i--);
        for(j = i;j>=0;j--)
        {
            if(s[j] == ' ')
            {
                last = j;
                break;
            }
        }
        if(j == -1)
            return i+1;
        if(last == -1)
            return 0;
        else
            return (i-last);
    }
};