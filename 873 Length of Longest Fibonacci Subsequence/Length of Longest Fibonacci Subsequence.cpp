class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<int> temp(A.size(),2);
        vector<vector<int>> res(A.size(), temp);
        map<int,int> M;
        for(int i = 0;i<A.size();i++) {
            M[A[i]] = i;
        }
        int ret = 2;
        for(int i = 2;i<A.size();i++) {
            for(int j = 1;j<i;j++) {
                // j,i
                int num = A[i]-A[j];
                if(num < A[j] && M.count(num) != 0) {
                    int t = M[num];
                    res[j][i] = 1+res[t][j];
                    ret = max(ret, res[j][i]);
                }
            }
        }
        return ret == 2 ? 0 : ret;
    }
};