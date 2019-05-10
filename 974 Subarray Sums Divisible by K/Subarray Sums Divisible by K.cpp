class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> v(K, 0);
        v[0] = 1;
        long base = 0;
        for(int i = 0;i<A.size();i++) {
            base += A[i];
            v[(base+long(INT_MAX)*K) % K] += 1;
        }
        int res = 0;
        for(int i = 0;i<K;i++) {
            res += (v[i]-1)*v[i]/2;
        }
        return res;
    }
};