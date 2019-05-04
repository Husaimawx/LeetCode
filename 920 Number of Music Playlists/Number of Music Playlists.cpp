class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> res(L+1, vector<long>(N+1,0));
        res[1][1] = 1;
        for(int i = 2;i<=L;i++) {
            for(int j = 1;j<=N;j++) {
                res[i][j] = ((N-j+2)*res[i-1][j-1]+max(j-K,0)*res[i-1][j])%1000000007;
            }
        }
        //for(int i = 0;i<=L;i++) {
        //    for(int j = 0;j<=N;j++) {
        //        cout << res[i][j];
        //    }
        //    cout << endl;
        //}
        return res[L][N];
    }
};