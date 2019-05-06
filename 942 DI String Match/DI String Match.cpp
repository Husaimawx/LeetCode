class Solution {
public:
    vector<int> diStringMatch(string S) {
        double base = 0;
        map<double,int> M;
        M[0] = 0;
        double add = 0.1/S.size();
        for(int i = 0;i<S.size();i++) {
            if(S[i] == 'I') {
                base += 1;
                M[base+add*(i+1)] = i+1;
            } else {
                base -= 1;
                M[base+add*(i+1)] = i+1;
            }
        }
        int f = 0;
        vector<int> res(S.size()+1,0);
        for(auto iter = M.begin();iter != M.end();iter++) {
            res[iter->second] = f;
            f++;
        }
     }
};