class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        int sign = 1;
        long long value = 0;
        int i;
        for(i = 0;i < length && str[i] == ' ';i++);
        if(i == length)
            return 0;
        
        if(str[i] == '+')
            i++;
        else if(str[i] == '-')
        {
            sign = -1;
            i++;
        }
        
        for(;i<length;i++)
        {
            if(str[i]-'0'<0 || str[i]-'0'>9)
                break;
            value = value*10 + str[i]-'0';
            if(value > INT_MAX)
            {
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        
        return sign*value;
    }
};