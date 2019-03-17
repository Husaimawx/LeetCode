class Solution {
public:
    int countPalindromicSubsequences(string S) {
        //dynamic programming copy from HUAHUA
        int n=S.size();
        vector<vector <int> >dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        for(int len=1;len<n;len++){
            for(int i=0;i<n-len;i++){
                 int j=i+len;
                //首尾相等
                if(S[i]==S[j]){
                    dp[i][j]=dp[i+1][j-1]*2;
                //find "b|bcab|b"
                    int l=i+1,r=j-1;
                    while(l<=r&&S[l]!=S[i]) l++;
                    while(l<=r&&S[r]!=S[i]) r--;
                //case 1: bcbcb 中间有与首尾元素相等的元素
                    if(l==r){
                        dp[i][j]+=1;
                    }
                //case 2: bccb 中间元素没有与首尾相等元素且中间元素相等
                    if(l>r){
                        dp[i][j]+=2;
                    }
                //case 3: bbcabb=>ca
                    else{dp[i][j]-=dp[l+1][r-1];}
                }
                //首尾不等
                else{dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];}
                dp[i][j]=(KMod+dp[i][j])%KMod;
            }
        }
        return dp[0][n-1];
    }
    private: static constexpr long KMod=1000000007;
};