class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> M;
        for(int i = 0;i<J.size();i++)
            M[J[i]] = 1;
        int res = 0;
        for(int i = 0;i<S.size();i++) {
            if(M.count(S[i]) == 1)
                res += 1;
        }
        return res;
    }
};