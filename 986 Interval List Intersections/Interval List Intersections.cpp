class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int f1 = 0;
        int f2 = 0;
        while(f1 != A.size() && f2 != B.size()) {
            if(A[f1][0] > B[f2][1])
                f2+=1;
            else if(B[f2][0] > A[f1][1])
                f1+=1;
            else {
                res.push_back(vector<int>{max(B[f2][0],A[f1][0]),min(B[f2][1],A[f1][1])});
                if(B[f2][1] <= A[f1][1])
                    f2+=1;
                else
                    f1+=1;
            }
        }
        return res;
    }
};