class MagicDictionary {
    unordered_map<string,vector<char>> M;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        M.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string& s : dict) {
            for(int i = 0;i<s.size();i++) {
                M[s.substr(0,i)+"*"+s.substr(i+1,s.size()-i-1)].push_back(s[i]);
            }
        }
        return;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string s) {
        for(int i = 0;i<s.size();i++) {
            if(M.count(s.substr(0,i)+"*"+s.substr(i+1,s.size()-i-1))) {
                if(M[s.substr(0,i)+"*"+s.substr(i+1,s.size()-i-1)].size() >1 || M[s.substr(0,i)+"*"+s.substr(i+1,s.size()-i-1)][0] != s[i])
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */