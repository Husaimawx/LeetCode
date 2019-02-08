class Solution {
public:
    int kInversePairs(int n, int k) {
        if(n == 0)
            return 0;
        if(k == 0)
            return 1;
        
        vector<int> temp(k+1, 0);
        vector<vector<int>> DP(n+1,temp);
        
        DP[1][0] = 1;
        for(int i = 2;i<=n;i++) {
            DP[i][0] = 1;
            int bound = min(k,i*(i-1)/2);
            for(int j = 1;j<=bound;j++) {
                if(j>=i)
                    DP[i][j] = DP[i-1][j]+DP[i][j-1]-DP[i-1][j-i];
                else
                    DP[i][j] = DP[i-1][j]+DP[i][j-1];

                DP[i][j] = (DP[i][j] % 1000000007);
                if(DP[i][j] < 0)
                    DP[i][j] += 1000000007;
            }
        }
        //cout << DP[13][52] << endl;
        //cout << DP[14][51] << endl;
        //cout << DP[13][38] << endl;
        return DP[n][k];
    }
};