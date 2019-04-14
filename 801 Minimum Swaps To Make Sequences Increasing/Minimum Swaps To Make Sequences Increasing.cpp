class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> res1(A.size(),0);
        vector<int> res2(A.size(),0);
        
        if(A[0] > B[0])
            res2[0] = 1;
        if(A[0] < B[0])
            res1[0] = 1;
        
        for(int i = 1;i<A.size();i++) {
            if(A[i] == B[i]) {
                res1[i] = min(res1[i-1], res2[i-1]);
                res2[i] = res1[i];
            } else {
                res1[i] = (A[i] < B[i]);
                res2[i] = (A[i] > B[i]);
                // res1
                if(min(A[i],B[i]) > max(A[i-1],B[i-1]))
                    res1[i] += min(res1[i-1],res2[i-1]);
                else
                    res1[i] += res1[i-1];
                // res2
                if(min(A[i],B[i]) > max(A[i-1],B[i-1]))
                    res2[i] += min(res1[i-1],res2[i-1]);
                else
                    res2[i] += res2[i-1];
            }
        }
        return min(res1[res1.size()-1],res2[res2.size()-1]);
    }
};