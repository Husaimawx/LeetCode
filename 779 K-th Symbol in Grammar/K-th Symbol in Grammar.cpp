class Solution {
public:
    int kthGrammar(int N, int K) {
        vector<int> pw(N,1);
        for(int i = 1;i<pw.size();i++) {
            pw[i] = 2*pw[i-1];
        }
        
        return subkth(N,K,pw);
    }
    
    int subkth(int N, int K, vector<int>& pw) {
        if(N == 1)
            return 0;
        if(N == 2)
            return K-1;
        if(K <= pw[N-2])
            return subkth(N-1,K,pw);
        else
            return 1-subkth(N-1, K-pw[N-2],pw);
    }
};