class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size(),0);
        int f1 = 0;
        int f2 = 1;
        for(int i = 0;i<A.size();i++) {
            if(A[i] % 2 == 0) {
                res[f1] = A[i];
                f1 += 2;
            } else {
                res[f2] = A[i];
                f2 += 2;
            }
        }
        return res;
    }
};