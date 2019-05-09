class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> v(A[0].size(),1);
        for(int i = 1;i<v.size();i++) {
            // v[i]
            for(int j = 0;j<i;j++) {
                int k;
                for(k = 0;k<A.size();k++) {
                    if(A[k][j] > A[k][i])
                        break;
                }
                if(k == A.size()) {
                    v[i] = max(1+v[j],v[i]);
                }
            }
        }
        int res = 1;
        for(int i = 0;i<v.size();i++) {
            //cout << v[i];
            res = max(res,v[i]);
        }
        return A[0].size()-res;
    }
};