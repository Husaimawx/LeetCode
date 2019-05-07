class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int tok = 1;
        int power = 0;
        int res = 0;
        sort(tokens.begin(),tokens.end());
        tokens.push_back(P);
        int from = 0;
        int to = tokens.size()-1;
        while(from < to) {
            tok -= 1;
            power += tokens[to];
            while(from < to && power >= tokens[from]) {
                power -= tokens[from];
                tok+=1;
                from += 1;
            }
            to -= 1;
            if(tok == 0)
                return res;
            res = max(res, tok);
        }
        return res;
    }
};