class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, int> M;
        M[s] = 1;
        
        vector<string> res;
        vector<string> v;
        v.push_back(s);
        int from = 0;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                if(check(v[i])) {
                    res.push_back(v[i]);
                }
                for(int j = 0;j<v[i].size();j++) {
                    if(v[i][j] != '(' && v[i][j] != ')') {
                        continue;
                    }
                    string temp = v[i].substr(0,j)+v[i].substr(j+1,v[i].size()-j-1);
                    if(M.count(temp) == 0) {
                        M[temp] = 1;
                        v.push_back(temp);
                    }
                }
            }
            from = to;
            if(res.size() != 0)
                return res;
        }
        return res;
    }
    
    bool check(string s) {
        int base = 0;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '(') {
                base += 1;
            } else if(s[i] == ')') {
                if(base == 0)
                    return false;
                base -= 1;
            }
        }
        return (base == 0);
    }
};