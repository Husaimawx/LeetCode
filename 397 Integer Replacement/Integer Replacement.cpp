class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1)
            return 0;
        if(n % 2 == 0)
            return integerReplacement(n >> 1)+1;
        int res1 = integerReplacement(n >> 1)+2;
        int res2 = integerReplacement((n >> 1)+1)+2;
        return res1 > res2 ? res2 : res1;
    }
};