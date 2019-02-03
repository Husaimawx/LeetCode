class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<long> temp(n,0);
        vector<vector<long>> dp(m, temp);
        int num = pow(10,9)+7;
        
        dp[i][j] = 1;
        long res = 0;
        for(int t = 0;t<N;t++) {
            vector<vector<long>> dp2(m,temp);
            for(int i = 0;i<m;i++) {
                for(int j = 0;j<n;j++) {
                    if(i != 0)
                        dp2[i-1][j] += dp[i][j];
                    else
                        res += dp[i][j];
                    if(i+1 != m)
                        dp2[i+1][j] += dp[i][j];
                    else
                        res += dp[i][j];
                    if(j != 0)
                        dp2[i][j-1] += dp[i][j];
                    else
                        res += dp[i][j];
                    if(j+1 != n)
                        dp2[i][j+1] += dp[i][j];
                    else
                        res += dp[i][j];
                    
                    res = res % num;
                }
            }
            for(int i = 0;i<m;i++) {
                for(int j = 0;j<n;j++) {
                    dp[i][j] = dp2[i][j]%num;
                }
            }
        }
        return res;
    }
};