class Solution {
public:
    string shortestSuperstring(vector<string>& A) {        
        vector<vector<int>> g(A.size(),vector<int>(int(A.size())));
        for(int i = 0;i<A.size();i++) {
            for(int j = 0;j<A.size();j++) {
                if(i == j)
                    continue;
                else
                    g[i][j] = distance(A[i],A[j]);
            }
        }
        
        vector<vector<int>> dp(1<<A.size(),vector<int>(int(A.size())));
        vector<vector<int>> pa(1<<A.size(),vector<int>(int(A.size())));
        
        for(int i = 1;i<(1<<A.size());i++) {
            vector<int> chosen;
            for(int j = 0;((i>>j)!= 0);j++) {
                if((i >> j)%2 == 1)
                    chosen.push_back(j);
            }
            for(int j = 0;j<chosen.size();j++) {
                // chosen[j] as last
                int remain = i-1<<chosen[j];
                for(int k = 0;k<chosen.size();k++) {
                    if(k == j)
                        continue;
                    if(dp[remain][chosen[i]]+g[chosen[k]][chosen[j]] >= dp[i][chosen[j]]) {
                        dp[i][chosen[j]] = dp[remain][chosen[i]]+g[chosen[k]][chosen[j]];
                        pa[i][chosen[j]] = chosen[i];
                    }
                }
            }
            if(i+1 == (1<<A.size())) {
                int mn = 0;
                int pos = 0;
                for(int j = 0;j<chosen.size();j++) {
                    if(dp[i][chosen[i]] >= mn) {
                        mn = dp[i][chosen[i]];
                        pos = chosen[i];
                    }
                }
                string res = A[pos];
                while(1) {
                    i -= (1<<pos);
                    if(i == 0)
                        return res;
                    int pre = pos;
                    pos = pa[i][pos];
                    res = A[pos].substr(0,A[pos].size()-g[pos][pre])+res;
                }
            }
        }
        return "";
    } 
    
    int distance(string& a, string& b) {
        int mindis = min(a.size(), b.size());
        for(int i = mindis-1;i>0;i--) {
            if(a.substr(a.size()-i,i) == b.substr(0,i))
                return i;
        }
        return 0;
    }
};