class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN)
        {
            if(dividend < 0)
                return 1;
            else
                return 0;
        }
        if(dividend == INT_MIN)
        {
            if(divisor == 1)
                return INT_MIN;
            if(divisor == -1)
                return INT_MAX;
        }
        
        int sign = 1;
        if(divisor < 0)
        {
            sign = -1;
            divisor = -divisor;
        }
        
        int ans = -1;
        if(dividend > 0)
        {
            while(dividend >= 0)
            {
                dividend -= divisor;
                ans++;
            }
            return (ans*sign);
        }
        else
        {
            while(dividend <= 0)
            {
                dividend += divisor;
                ans++;
            }
            return (ans*sign*-1);
        }
    }
}; // Time limitation exceed

//other people's answer
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) { 
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res; 
    }
};

//my accept solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign1 = 1,sign2 = 1;
        long long dvd = dividend,dor = divisor;
        if(dividend < 0)
        {
            sign1 = -1;
            dvd = -dvd;
        }
        if(divisor < 0)
        {
            sign2 = -1;
            dor = -dor;
        }
        
        int ans = 0;
        while(dvd >= dor)
        {
            long long temp = dor, multiple = 1;
            while(dvd >= (temp<<1))
            {
                temp = temp<<1;
                multiple = multiple<<1;
            }
            dvd -= temp;
            ans += multiple;
        }
        return (sign1*sign2*ans);
    }
};