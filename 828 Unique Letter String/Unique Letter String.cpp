class Solution {
public:
    int uniqueLetterString(string S) {
        vector<int> temp(1,-1);
        vector<vector<int>> v(26,temp);
        for(int i = 0;i<S.size();i++) {
            v[S[i]-'A'].push_back(i);
        }
        //cout << v[0].size() << v[1].size() << v[2].size();
        int res = 0;
        for(int i = 0;i<26;i++) {
            v[i].push_back(S.size());
            for(int j = 1;j+1<v[i].size();j++) {
                res += (v[i][j]-v[i][j-1])*(v[i][j+1]-v[i][j]);
            }
        }
        return res;
    }
};