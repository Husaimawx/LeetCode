class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        
        int base = 1;
        if(n % 3 == 2)
        {
            base = 2;
            n = (n-2)/3;
        }
        else if(n % 3 == 1)
        {
            base = 4;
            n = (n-4)/3;
        }
        else
            n = n/3;
        
        for(int i = 0;i<n;i++)
            base *= 3;
        
        return base;
    }
};