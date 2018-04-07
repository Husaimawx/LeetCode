class Solution {
public:
    int reverse(int x) {
        if(x == 0)
        {
            return 0;
        }

        int sign = 1;
        if(x < 0)
        {
            sign = -1;
            x *= -1;
        }
        long long int ans = 0;
        
        while(x != 0)
        {
            ans = ans*10 + x%10;
            x = x/10;
        }
        ans *= sign;
        
        return (ans<INT_MIN || ans>INT_MAX) ? 0 : ans;
    }
};