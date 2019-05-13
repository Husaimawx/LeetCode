class Solution {
public:
    int numPermsDISequence(string S) {
        vector<long> res(S.size()+1,0);
        res[0] = 1;
        for(int i = 0;i<S.size();i++) {
            if(S[i] == 'I') {
                for(int j = 0;j<=i;j++)
                    res[i+1] = (res[i+1]+res[j])%1000000007;
                for(int j = i;j>=0;j--)
                    res[j] = (res[j+1]-res[j])%1000000007;
            } else {
                for(int j = i-1;j>=0;j--) {
                    res[j] = (res[j]+res[j+1])%1000000007;
                }
            }
            //for(int i = 0;i<=S.size();i++)
            //    cout << res[i];
            //cout << endl;
        }
        long ret = 0;
        for(int i = 0;i<=S.size();i++)
            ret += res[i];
        while(ret < 0)
            ret += 1000000007;
        return ret%1000000007;
    }
};