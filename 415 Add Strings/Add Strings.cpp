class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() == 0)
            return num2;
        if(num2.size() == 0)
            return num1;
        
        if(num1.size() < num2.size())
        {
            string temp(num2.size()-num1.size(),'0');
            num1 = temp + num1;
        }
        else
        {
            string temp(num1.size()-num2.size(),'0');
            num2 = temp + num2;            
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int c = 0;
        string res("");
        for(int i = 0;i<num1.size();i++)
        {
            int sum = (num1[i]-'0')+(num2[i]-'0')+c;
            if(sum < 10)
            {
                char temp = '0'+sum;
                res = temp + res;
                c = 0;
            }
            else
            {
                c = 1;
                char temp = '0'+sum-10;
                res = temp + res;
            }
        }
        if(c == 1)
            res = "1"+res;
        return res;
    }
};