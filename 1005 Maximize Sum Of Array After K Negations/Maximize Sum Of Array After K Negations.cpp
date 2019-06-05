class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int i;
        for(i = 0;i<A.size() && A[i] < 0;i++) {
            A[i] *= -1;
            K-=1;
            if(K == 0)
                break;
        }
        
        if(K != 0 && K % 2==1) {
            if(i == A.size())
                A[i-1] *= -1;
            else if(i == 0) {
                A[0] *= -1;
            } else {
                if(A[i] < A[i-1])
                    A[i]*=-1;
                else
                    A[i-1]*=-1;
            }
        }
        
        int res = 0;
        for(auto item : A)
            res += item;
        return res;
    }
};