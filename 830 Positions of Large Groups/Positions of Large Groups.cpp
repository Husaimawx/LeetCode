class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        S = S + "5";
        vector<vector<int>> res;
        int from = 0;
        for(int i = 1;i<S.size();i++) {
            if(S[i] != S[i-1]) {
                if(i-from >= 3) {
                    res.push_back(vector<int>{from,i-1});
                }
                from = i;
            }
        }
        return res;
    }
};