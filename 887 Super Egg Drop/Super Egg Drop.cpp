class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> res(N+1, vector<int>(K+1,0));
        for(int m = 1;m<=N;m++) {
            for(int k = 1;k<=K;k++) {
                res[m][k] = res[m-1][k-1]+res[m-1][k]+1;
                if(res[m][k] >= N)
                    return m;
            }
        }
        return N;
    }
};