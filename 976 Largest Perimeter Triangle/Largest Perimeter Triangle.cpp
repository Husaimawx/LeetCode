class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size()<3)
            return 0;
        sort(A.begin(),A.end());
        for(int i = A.size()-3;i>=0;i--) {
            if(A[i]+A[i+1]>A[i+2])
                return (A[i]+A[i+1]+A[i+2]);
        }
        return 0;
    }
};