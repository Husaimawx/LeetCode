class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if(A.size() == 1)
            return 0;
        sort(A.begin(),A.end());
        int res = A[A.size()-1]-A[0];
        for(int i = 0;i+1<A.size();i++) {
            int temp = max(A[A.size()-1]-K,A[i]+K)-min(A[0]+K,A[i+1]-K);
            res = min(res,temp);
        }
        return res;
    }
};