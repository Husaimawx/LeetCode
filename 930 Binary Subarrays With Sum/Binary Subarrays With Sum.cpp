class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> M;
        M[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0;i<A.size();i++) {
            sum += A[i];
            res += M[sum-S];
            if(M.count(sum) == 0)
                M[sum] = 1;
            else
                M[sum] += 1;
        }
        return res;
    }
};