class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int i = 0;
        int oldm = m,oldn = n;
        while(m)
        {
            i++;
            m = m>>1;
        }
        int j = 0;
        while(n)
        {
            j++;
            n = n>>1;
        }

        if(i != j)
            return 0;

        while(i>0)
        {
            if(((oldn >> (i-1))&1) != ((oldm >> (i-1))&1))
                return res;
            if((oldn >> (i-1))&1)
                res += (1 << (i-1));
            i--;    
        }
        return res;
    }
    
    
};