class Solution {
public:
    int findKthNumber(int n, int k)
    {
        long myn = n;
        long myk = k;
        long res = 1;
        
        while(myk != 0) {
            long from = res;
            long to = res+1;
            long count = 0;
            while(from <= myn) {
                count += (min(to, myn+1)-from);
                from *= 10;
                to *= 10;
            }
            
            if®(myk > count) {
                myk-=count;
                res+=1;
            } else {
                res*=10;
            }
        }
        
        return res;
    }
};