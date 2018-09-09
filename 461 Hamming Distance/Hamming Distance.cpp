class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int result = 0;
        while(z!=0)
        {
            if(z&1 == 1)
            {
                result++;
            }
            z >>= 1;
        }
        return result;
    }
};