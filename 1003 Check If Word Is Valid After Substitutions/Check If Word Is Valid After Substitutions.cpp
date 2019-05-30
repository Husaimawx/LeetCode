class Solution {
public:
    bool isValid(string S) {
        if(S.size()<3 || S.size() % 3 != 0)
            return false;
        vector<char> v(S.size());
        v[0] = S[0];
        v[1] = S[1];
        int to = 2;
        for(int i = 2;i<S.size();i++) {
            v[to] = S[i];
            while(to>=2 && (v[to] == 'c' && v[to-1] == 'b' && v[to-2] == 'a'))
                to -= 3;
            to += 1;
        }
        return (to == 0);
    }
};