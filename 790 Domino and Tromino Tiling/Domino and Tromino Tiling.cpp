class Solution {
public:
    int numTilings(int N) {
        if(N < 3)
            return N;
        
        vector<long> temp(2,1);
        vector<vector<long>> res(N, temp);
        
        res[1][0] = 2;
        res[1][1] = 2;
        for(int i = 2;i<N;i++) {
            res[i][0] = (res[i-1][0] + res[i-2][0] + 2*res[i-2][1])%(1000000007);
            res[i][1] = (res[i-1][0] + res[i-1][1])%(1000000007);
        }
        return res[N-1][0];
    }
};