class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i = 0;i<words.size();i++) {
            if(check(words[i], pattern) && check(pattern, words[i]))
                res.push_back(words[i]);
        }
        return res;
    }
    
    bool check(string& a, string& b) {
        map<char,char> M;
        for(int i = 0;i<a.size();i++) {
            if(M.count(a[i]) == 0) {
                M[a[i]] = b[i];
            } else {
                if(M[a[i]] != b[i])
                    return false;
            }
        }
        return true;
    }
};