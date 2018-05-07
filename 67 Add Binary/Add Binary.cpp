class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0)
            return b;
        if(b.size() == 0)
            return a;
        if(a.size()<b.size())
        {
            string temp(b.size()-a.size(),'0');
            a = temp+a;
        }
        else
        {
            string temp(a.size()-b.size(),'0');
            b = temp+b;            
        }
        
        int plus = 0;
        int temp2;
        string res = "";
        for(int i = a.size()-1; i>=0;i--)
        {
            temp2 = plus+(a[i]-'0')+(b[i]-'0');
            if(temp2 > 1)
            {
                temp2 -= 2;
                plus = 1;
            }
            else
                plus = 0;
            res = to_string(temp2)+res;
        }
        if(plus !=0)
            res = to_string(1)+res;
        return res;
    }
};