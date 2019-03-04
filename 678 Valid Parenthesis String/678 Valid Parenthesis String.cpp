class Solution {
public:
    bool checkValidString(string s) {
        if(s.size() == 0)
            return true;
        int num1 = 0,num2 = 0;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '(')
                num1 += 1;
            if(s[i] == ')')
                num2 += 1;
        }
        int num3 = s.size()-num1-num2;
        if(num1 > num3+num2 || num2 > num1+num3)
            return false;
        int quant = s.size()/2-num1;
        
        int remain = 0;
        int flag = s.size() % 2;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '*') {
                if(quant > 0) {
                    s[i] = '(';
                    quant -= 1;
                } else if(flag == 1) {
                    flag = 0;
                    continue;
                } else {
                    s[i] = ')';
                }
            }
            
            if(s[i] == '(')
                remain += 1;
            else if(s[i] == ')') {
                if(remain == 0)
                    return false;
                else
                    remain -= 1;
            }
        }
        return true;
    }
};