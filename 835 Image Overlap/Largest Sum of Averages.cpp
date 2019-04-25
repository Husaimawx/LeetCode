class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        int res = 0;
        for(int i = -N+1;i<N;i++) {
            for(int j = -N+1;j<N;j++) {
                int tres = 0;
                for(int k = 0;k<N;k++) {
                    for(int t = 0;t<N;t++) {
                        if(0<=i+k && i+k < N && j+t>=0 && j+t<N) {
                            tres += A[i+k][j+t]*B[k][t];
                        }
                    }
                }
                res = max(res, tres);
            }
        }
        return res;
    }
};