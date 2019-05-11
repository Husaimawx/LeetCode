class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0;
        int base = 0;
        vector<int> B(A.size(), 0);
        for(int i = 0;i<A.size();i++) {
            if(i>=K)
                base -= B[i-K];
            if((base+A[i])%2 != 1) {
                if(i>A.size()-K)
                    return -1;
                res += 1;
                base += 1;
                B[i] = 1;
            }
        }
        
        return res;
    }
};