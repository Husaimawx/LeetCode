class Solution {
public:
    int minAddToMakeValid(string S) {
        int base = 0;
        int res = 0;
        for(int i = 0;i<S.size();i++) {
            if(S[i] == ')') {
                if(base > 0)
                    base -= 1;
                else
                    res += 1;
            } else {
                base += 1;
            }
        }
        res += base;
        return res;
    }
};