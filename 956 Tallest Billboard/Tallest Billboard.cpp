class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if(rods.size() == 0)
            return 0;
        int sum = 0;
        for(int i = 0;i<rods.size();i++) {
            sum += rods[i];
        }
        sum=sum/2+1;
        vector<vector<int>> dp(rods.size(), vector<int>(sum+1,INT_MIN));
        if(rods[0] <= sum)
            dp[0][rods[0]] = 0;
        dp[0][0] = 0;
        for(int i = 1;i<rods.size();i++) {
            if(rods[i] < sum) {
                for(int j = 0;j<=sum;j++) {
                   if(dp[i-1][j] == INT_MIN)
                       continue;
                    if(j+rods[i] <= sum) {
                        dp[i][j+rods[i]] = max(dp[i][j+rods[i]], dp[i-1][j]);
                    }
                    if(j >= rods[i]) {
                        dp[i][j-rods[i]] = max(dp[i][j-rods[i]], dp[i-1][j]+rods[i]);
                    } else {
                        dp[i][rods[i]-j] = max(dp[i][rods[i]-j], dp[i-1][j]+j);
                    }
                }
            }
            for(int j = 0;j<=sum;j++) {
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
        //for(int i = 0;i<dp.size();i++) {
        //    for(int j = 0;j<dp[0].size();j++) {
        //        cout << dp[i][j] << ' ';
        //    }
        //    cout << endl << endl;
        //}
        return max(dp[rods.size()-1][0],0);
    }
};