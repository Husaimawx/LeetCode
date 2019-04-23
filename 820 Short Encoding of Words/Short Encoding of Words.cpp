class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(int i = 0;i<words.size();i++) {
            reverse(words[i].begin(), words[i].end());
        }
        sort(words.begin(),words.end());
        int res = 0;
        for(int i = 0;i<words.size();i++) {
            if(i+1 == words.size() || contain(words[i], words[i+1]) == 0) {
                res += (words[i].size()+1);
            }
        }
        return res;
    }
    
    bool contain(string& a, string& b) {
        if(a.size() > b.size())
            return false;
        for(int i = 0;i<a.size();i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};