class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1)
            return A[0];
        int res = INT_MIN;
        vector<int> sum(A.size(),A[0]);
        for(int i = 1;i<A.size();i++) {
            sum[i] = sum[i-1]+A[i];
        }
        int minnum = 0;
        for(int i = 0;i<A.size();i++) {
            res = max(res, sum[i]-minnum);
            minnum = min(minnum,sum[i]);
        }
        
        for(int i = 1;i<A.size();i++)
            sum[i] = max(sum[i],sum[i-1]);
            
        int base = 0;
        for(int i = A.size()-1;i>0;i--) {
            base += A[i];
            res = max(res, base+sum[i-1]);
        }
        return res;
    }
};