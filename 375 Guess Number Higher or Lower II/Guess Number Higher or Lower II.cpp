class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> res(n + 1, vector<int>(n + 1));
        for(int i = 1;i<=n;i++) {
            res[i][i] = 0;
        }
        
        for(int dis = 1; dis<n; dis++) {
            for(int from = 1;from+dis <= n;from++) {
                int r = INT_MAX;
                for(int i = from;i<=from+dis;i++) {
                    int left = 0;
                    int right = 0;
                    if(from < i)
                        left = res[from][i-1];
                    if(i+1 <= from+dis)
                        right = res[i+1][from+dis];
                    if(r > max(right, left)+i)
                        r = max(right, left)+i;
                }
                res[from][from+dis] = r;
            }
        }
        return res[1][n];
    }
};