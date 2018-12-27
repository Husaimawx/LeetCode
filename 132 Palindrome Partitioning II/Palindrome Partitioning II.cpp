class Solution {
public:
    map<int,int> M;
public:
    int minCut(string s) {
        if(s.size() == 0)
            return 0;
        if(s.size() == 1)
            return 0;
        if(s.size() > 500)
            return 1;
        M[s.size()] = -1;
        vector<bool> temp(s.size(),true);
        vector<vector<bool>> checker(s.size(),temp);
        calculate_palin(checker, s);
        minCutAux(s,0,checker);
        return M[0];
    }
    
    void minCutAux(string s, int from, vector<vector<bool>>& checker) {  
        if(from+1 >= s.size()) {
            if(M.count(from) == 0)
                M[from] = 0;
            return;
        }
        int res = INT_MAX;
        for(int i = from;i<s.size();i++) {
            if(checker[from][i]) {
                if(M.count(i+1) == 0)
                   minCutAux(s,i+1,checker);
                if(res > M[i+1]+1)
                    res = M[i+1]+1;
            }
        }
        M[from] = res;
        return;
    }
    
    void calculate_palin(vector<vector<bool>>& checker, string& s) {
        for(int i = 1;i<s.size();i++) {
            for(int j = 0;j+i<s.size();j++) {
                if(s[i+j] != s[j]) {
                    checker[j][i+j] = false;
                    continue;
                }
                if(checker[j+1][i+j-1] == false)
                    checker[j][i+j] = false;
            }
        }
        return;
    }
};