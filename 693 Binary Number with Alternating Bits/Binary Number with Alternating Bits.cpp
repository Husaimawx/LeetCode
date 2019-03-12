class Solution {
public:
    bool hasAlternatingBits(int n) {
        int sign = n%2;
        n = n/2;
        
        while(1) {
            if(n == 0)
                return true;
            if(sign == n%2)
                return false;
            sign = 1-sign;
            n = n/2;
        }
    }
};