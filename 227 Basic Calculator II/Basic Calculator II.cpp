class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int temp[2] = {0,1};
        int sign = 1;
        int sign2 = 1;
        int pos = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
                continue;
            if(s[i]<='9' && s[i]>='0')
            {
                temp[pos] = temp[pos]*10+s[i]-'0';
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(sign2 == 1)
                    ans += temp[0]*temp[1]*sign;
                else
                    ans += temp[0]/temp[1]*sign;
                temp[0] = 0;
                temp[1] = 1;
                sign2 = 1;
                pos = 0;
                if(s[i] == '+')
                    sign = 1;
                else
                    sign = -1;
            }
            else // if(s[i] == '*' || s[i] == '\')
            {
                if(sign2 == 1)
                    temp[0] *= temp[1];
                else
                    temp[0] /= temp[1];
                temp[1] = 0;
                pos = 1;
                if(s[i] == '*')
                    sign2 = 1;
                else
                    sign2 = -1;
            } 
        }
        
        if(sign2 == 1)
            ans += temp[0]*temp[1]*sign;
        else
            ans += temp[0]/temp[1]*sign;
        
        return ans;
    }
};