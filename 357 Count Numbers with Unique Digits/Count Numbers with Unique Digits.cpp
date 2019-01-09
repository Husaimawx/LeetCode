class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int res = 10;
        if(n == 1)
            return res;
        int temp = 81;
        res+=temp;
        if(n == 2)
            return res;
        temp*=8;
        res+=temp;
        if(n == 3)
            return res;
        temp*=7;
        res+=temp;
        if(n == 4)
            return res;
        temp*=6;
        res+=temp;
        if(n == 5)
            return res;
        temp*=5;
        res+=temp;
        if(n == 6)
            return res;
        temp*=4;
        res+=temp;
        if(n == 7)
            return res;
        temp*=3;
        res+=temp;
        if(n == 8)
            return res;
        temp*=2;
        res+=temp;
        if(n == 9)
            return res;
        temp*=1;
        res+=temp;
        return res;
    }
};