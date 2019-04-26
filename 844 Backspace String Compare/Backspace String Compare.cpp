class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return convert(S) == convert(T);
    }
    
    string convert(string& s) {
        string res;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '#') {
                if(res.size() != 0)
                    res.pop_back();
            }
            else
                res += s[i];
        }
        //cout << res << endl;
        return res;
    }
};