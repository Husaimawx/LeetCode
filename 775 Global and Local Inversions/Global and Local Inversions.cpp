class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if(A.size() < 3)
            return true;
        for(int i = 0;i+3 < A.size();i++) {
            if(A[i] > A[i+2] || A[i] > A[i+3])
                return false;
        }
        if(A[A.size()-3] > A[A.size()-1])
            return false;
        return true;
    }
};