class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int k = lastRemaining(n/2);
        return 2*(n/2+1-k);
    }
};