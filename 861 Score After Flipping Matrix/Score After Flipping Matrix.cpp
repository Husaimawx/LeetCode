class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        vector<vector<int>> B = A;
        
        int base = (1 << (A[0].size()-1));
        int res = base * A.size();
        for(int i = 0;i<A.size();i++) {
            if(A[i][0] == 0) {
                for(int j = 0;j<A[0].size();j++) {
                    A[i][j] = 1-A[i][j];
                }
            }
        }

        for(int i = 1;i<A[0].size();i++) {
            base /= 2;
            int temp = 0;
            for(int j = 0;j<A.size();j++)
                temp += A[j][i];
            res += base*max(temp,int(A.size())-temp);
        }
                
        base = (1 << (A[0].size()-1));
        int res2 = base * B.size();
        for(int i = 0;i<A.size();i++)
            B[i][0] = 1-B[i][0];
        for(int i = 0;i<B.size();i++) {
            if(B[i][0] == 0) {
                for(int j = 0;j<B[0].size();j++) {
                    B[i][j] = 1-B[i][j];
                }
            }
        }
        
        for(int i = 1;i<B[0].size();i++) {
            base /= 2;
            int temp = 0;
            for(int j = 0;j<B.size();j++)
                temp += B[j][i];
            res2 += base*max(temp,int(B.size())-temp);
        }
        
        return max(res,res2);
    }
};