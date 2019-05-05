class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> one(S.size(),0);
        if(S[0] == '1')
            one[0] = 1;
        for(int i = 1;i<S.size();i++) {
            one[i] = one[i-1]+(S[i] == '1');
        }
        
        vector<int> zero(S.size(),0);
        if(S[S.size()-1] == '0')
            zero[S.size()-1] = 1;
        for(int i = int(S.size())-2;i>=0;i--) {
            zero[i] = zero[i+1]+(S[i] == '0');
        }
        
        int res = INT_MAX;
        for(int i = 0;i<S.size()-1;i++) {
            res = min(res,one[i]+zero[i+1]);
        }
        res = min(res,one[S.size()-1]);
        res = min(res, zero[0]);
        return res;
    }
};