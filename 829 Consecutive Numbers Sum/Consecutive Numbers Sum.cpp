class Solution {
public:
    int consecutiveNumbersSum(int N) {
        long m = 2*N;
        int res = 0;
        for(long i = 1;i*i+i <= m;i++) {
            if(m%i == 0 && (m/i-i)%2 == 1)
                res++;
        }
        return res;
    }
};