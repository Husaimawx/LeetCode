class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int f1 = 0;
        int f2 = 0;
        for(int i = 1;i<A.size();i++) {
            if(A[i] > A[i-1])
                f1 += 1;
            else if(A[i] < A[i-1])
                f2 += 1;
        }
        if(f1 == 0 || f2 == 0)
            return true;
        return false;
    }
};