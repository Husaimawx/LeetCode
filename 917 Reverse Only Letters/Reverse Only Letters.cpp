class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.size() < 2)
            return S;
        int from = 0;
        int to = S.size()-1;
        while(1) {
            while(from < S.size() && !is_char(S[from]))
                from += 1;
            while(to >= 0 && !is_char(S[to]))
                to -= 1;
            if(from >= to)
                break;
            else {
                swap(S[from],S[to]);
                from += 1;
                to -= 1;
            }
        }
        return S;
    }
    
    bool is_char(char c) {
        if(c <='z' && c >= 'a')
            return true;
        if(c <='Z' && c >= 'A')
            return true;
        return false;
    }
};