class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        for(int i = int(A.size())-2;i>=0;i--) {
            for(int j = 0;j<A.size();j++) {
                int minnum = A[i+1][j];
                if(j != 0) {
                    minnum = min(minnum,A[i+1][j-1]);
                }
                if(j != A.size()-1) {
                    minnum = min(minnum,A[i+1][j+1]);
                }
                A[i][j] += minnum;
            }
        }
        /*
        for(int i = 0;i<3;i++) {
            for(int j = 0;j<3;j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }*/
        int res = A[0][0];
        for(int i = 1;i<A.size();i++) {
            res = min(res,A[0][i]);
        }
        return res;
    }
};